#! /bin/bash

function usage ()
{
    echo "Build options:"
    echo ""
    echo "-h --help prints this message"
    echo "-t --target=<target>"
    echo ""
}

while [ "$1" != "" ]; do
    PARAM=`echo $1 | awk -F= '{print $1}'`
    VALUE=`echo $1 | awk -F= '{print $2}'`
    case $PARAM in
        -h | --help)
            usage
            exit
            ;;
        --target)
            target=$VALUE
            ;;
        *)
            echo "ERROR: unknown parameter \"$PARAM\""
            usage
            exit 1
            ;;
    esac
    shift
done

if [[ $target == "clean" ]]; then
	echo "Cleaning cache and reconfiguring cmake."
	rm -rf out/build/CMakeCache.txt
	./configure.sh
else
	make -C out/build/
fi
