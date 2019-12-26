cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_COMPILER clang++ CACHE STRING "C++ compiler" FORCE)

project(skeleton VERSION 0.0.1.0)
enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories("${CMAKE_BINARY_DIR}")
include_directories(${PROJECT_SOURCE_DIR})
include_directories(thirdparty/include)
include_directories(/usr/lib/llvm-9/include/c++/v1/)

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

add_compile_options(-Wall)
add_compile_options(-pipe)
add_compile_options(-fPIC)
add_compile_options(-std=c++17)
add_compile_options(-stdlib=libc++)
add_compile_options (-fcolor-diagnostics)
# add_compile_options(-nostdinc++)

add_executable(skeleton
    src/base/base.cpp
    src/base/base.h
    src/config.h.in
    src/skeleton.cpp
    src/skeleton.h
    src/main.cpp )

target_link_libraries(skeleton
    c++
    m
    c
    gcc_s
    gcc )

