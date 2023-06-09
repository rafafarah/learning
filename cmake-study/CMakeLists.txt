cmake_minimum_required(VERSION 3.13.4)

project(olas VERSION 1.0)

#			Adder use logic
option(USE_ADDER "A simple library for adding 2 floats." ON)

if(USE_ADDER)
	add_subdirectory(Adder)

	list(APPEND EXTRA_LIB_DIR "Adder")
	list(APPEND EXTRA_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Adder")
	list(APPEND EXTRA_LINK_LIB "adder")
endif()

configure_file(olasconfig.h.in olasconfig.h)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

# 			DOWNLOAD ALL THE SUBMODULES
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
	option(GIT_SUBMODULE "Check submodules during build" ON)
	if(GIT_SUBMODULE)
		message(STATUS "Submodule update")
		execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
						WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
						RESULT_VARIABLE GIT_SUBMOD_RESULT)
		if(NOT GIT_SUBMOD_RESULT EQUAL "0")
			message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
		endif()
	endif()
endif()

#			CHECK ALL THE SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
	message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
else()
	list(APPEND EXTRA_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/external/glfw/include")
	list(APPEND EXTRA_LIB_DIR "external/glfw/src")
	list(APPEND EXTRA_LINK_LIB "glfw")
endif()

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME}
	PUBLIC
	${EXTRA_INCLUDE_DIR}
)

target_link_directories(${PROJECT_NAME}
	PRIVATE
	${EXTRA_LIB_DIR}
)

target_link_libraries(${PROJECT_NAME}
	${EXTRA_LINK_LIB}
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/olasconfig.h" DESTINATION include)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include(CPack)
