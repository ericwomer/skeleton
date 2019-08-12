cmake_minimum_required(VERSION 3.14)
project(skeleton VERSION 0.0.1.0)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR})
include_directories(thirdparty/include)

# build configuration header file
set(name ${CMAKE_PROJECT_NAME})

set(compiler_name ${CMAKE_CXX_COMPILER_ID})
set(compiler_version ${CMAKE_CXX_COMPILER_VERSION})
set(host_machine ${CMAKE_HOST_SYSTEM_NAME})
set(cpu_family ${CMAKE_HOST_SYSTEM_PROCESSOR})

set(major ${PROJECT_VERSION_MAJOR})
set(minor ${PROJECT_VERSION_MINOR})
set(patch ${PROJECT_VERSION_PATCH})
set(compile ${PROJECT_VERSION_TWEAK})

# configure header file
configure_file(
        ${PROJECT_SOURCE_DIR}/src/config.h.in
        ${PROJECT_BINARY_DIR}/config.h
)

add_executable(skeleton
        src/base/base.cpp
        src/base/base.h
        src/config.h.in
        src/skeleton.cpp
        src/skeleton.h
        src/main.cpp
        )

target_link_libraries(skeleton)
