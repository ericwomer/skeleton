cmake_minimum_required(VERSION 3.15)

# Eric: Functionise this ugly section
get_filename_component(ProjectId ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
#string(TOLOWER ${ProjectId} ProjectId)
#string(SUBSTRING ${ProjectId} 0 1 FIRST_LETTER)
#string(TOUPPER ${FIRST_LETTER} FIRST_LETTER)
#string(REGEX REPLACE "^.(.*)" "${FIRST_LETTER}\\1" ProjectId "${ProjectId}")

# Set the project name using the above code.
project(${ProjectId} VERSION 0.0.1.0) # This is where you set your applications version
enable_language(CXX)

# Options Section.
option(USE_SPDLOG "Use spdlog for fancy log printing" ON)
option(BUILD_DOC "Build documentation" OFF)
option(FORCE_COLOR_OUTPUT "Force diagnostice color output (GNU/Clang compilers only)" ON)
option(USE_MOLD "Use mold linker instead of system default" OFF)

# Do not build documentation if the buid type isn't a variant of the Release type
if(BUILD_DOC AND CMAKE_BUILD_TYPE MATCHES "^[Dd]ebug")
        message(WARNING "Documentation is to be built only with Release, RelWithDebInfo, or MinSizeRel build types. BUILD_DOC has been manually forced to OFF")
        set(BUILD_DOC OFF)
endif()

# Generates the compile_commands.json file, which is used
# by several outside packages and some IDEs.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Make sure the compiler we are using can handle the standard we want to use.
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++20" COMPILER_SUPPORTS_CXX20)
if(COMPILER_SUPPORTS_CXX20)
    set(CMAKE_CXX_STANDARD 20)
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++20 support. Please use a different C++ compiler.")
endif()
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(USE_MOLD)
  find_program(HAVE_MOLD mold)
  if(HAVE_MOLD)
    message(STATUS "Using mold linker")
    add_compile_options(-fuse-ld=mold)
  else()
    message(STATUS "mold linker not found in system, using default linker")
  endif(HAVE_MOLD)
else()
  message(STATUS "Using default linker")
endif(USE_MOLD)

if(USE_SPDLOG)
    include_directories("${PROJECT_SOURCE_DIR}/thirdparty/spdlog/include/")
    add_definitions(-DUSE_SPDLOG) # Eric: Unused for the moment as spdlog is on by default and there are no alternatives.
endif()

# Default project include search paths.
include_directories("${CMAKE_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/src/")

# Building the config.h file.
set(name ${CMAKE_PROJECT_NAME})

set(compiler_name ${CMAKE_CXX_COMPILER_ID})
set(compiler_version ${CMAKE_CXX_COMPILER_VERSION})
set(host_machine ${CMAKE_HOST_SYSTEM_NAME})
set(cpu_family ${CMAKE_HOST_SYSTEM_PROCESSOR})

set(major ${PROJECT_VERSION_MAJOR})
set(minor ${PROJECT_VERSION_MINOR})
set(patch ${PROJECT_VERSION_PATCH})
set(compile ${PROJECT_VERSION_TWEAK})

# Generate the config.h file.
configure_file(
        ${PROJECT_SOURCE_DIR}/src/config.h.in
        ${PROJECT_BINARY_DIR}/config.h
)

# Build the documentation with doxygen if enabled
if(BUILD_DOC)
        add_subdirectory(${PROJECT_SOURCE_DIR}/doc)
endif(BUILD_DOC)

# Eric: Clean up and generalize this section to be used with MSVC, GCC, and CLang, not just one.
add_compile_options(-Wall)
add_compile_options(-pipe)
add_compile_options(-fPIC)

if(FORCE_COLOR_OUTPUT)
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        add_compile_options(-fdiagnostics-color=always)
    elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        add_compile_options (-fcolor-diagnostics)
    endif()
endif()

# Separate sources and header includes for different [modules]
# in case some need to be removed or added.
set(${CMAKE_PROJECT_NAME}_SOURCES
        src/Implementation/ApplicationImplementation.cpp
        src/main.cpp
        )

set(${CMAKE_PROJECT_NAME}_INCLUDES
        src/config.h.in # Eric: Shouldn't this be config.h?
        src/Interface/ApplicationInterface.h
        src/Implementation/ApplicationImplementation.h
        )

set(LOG_SOURCES
        src/log/log.cpp
        )
set(LOG_INCLUDES
        src/log/log.h
        )

# Eric: I believe these are only for Visual Studio but I am not sure.
source_group("${CMAKE_PROJECT_NAME}" FILES ${${CMAKE_PROJECT_NAME}_SOURCES})
source_group("${CMAKE_PROJECT_NAME}" FILES ${${CMAKE_PROJECT_NAME}_INCLUDES})

source_group("${CMAKE_PROJECT_NAME}\\log" FILES ${LOG_SOURCES})
source_group("${CMAKE_PROJECT_NAME}\\log" FILES ${LOG_INCLUDES})

# Append separated sources to the the primary source list
list(APPEND ${CMAKE_PROJECT_NAME}_SOURCES ${LOG_SOURCES})

# Clean up any duplicate source files that may have snuck in.
list(REMOVE_DUPLICATES ${CMAKE_PROJECT_NAME}_SOURCES)

# Lowercase the project name for use as the name of the executable
string( TOLOWER ${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_BINARY_NAME)
add_executable(${${CMAKE_PROJECT_NAME}_BINARY_NAME}
        ${${CMAKE_PROJECT_NAME}_SOURCES}
        )

# Manually added libraries go here. Use a list append later or just
# add the packages library variable to target_link_libraries function.
set(${CMAKE_PROJECT_NAME}_Libraries
        m
        c
        gcc_s
        gcc
        )

target_link_libraries(${${CMAKE_PROJECT_NAME}_BINARY_NAME}
        ${${CMAKE_PROJECT_NAME}_Libraries}
        )

