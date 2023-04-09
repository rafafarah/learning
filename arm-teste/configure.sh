#! /bin/sh

cmake -DUSE_ADDER=ON -DCMAKE_C_COMPILER=/usr/bin/arm-none-eabi-gcc -DCMAKE_C_FLAGS="--specs=nosys.specs" -DCMAKE_CXX_COMPILER=/usr/bin/arm-none-eabi-g++ -DCMAKE_CXX_FLAGS="--specs=nosys.specs -mcpu=cortex-m4" -S . -B out/build/
