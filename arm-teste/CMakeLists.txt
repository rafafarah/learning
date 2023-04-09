cmake_minimum_required(VERSION 3.13.4)

project(olas VERSION 1.0)

configure_file(olasconfig.h.in olasconfig.h)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

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