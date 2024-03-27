cmake_minimum_required(VERSION 3.10)
project(minibash C)

set(CMAKE_C_STANDARD 11)

# Find the readline library
find_library(READLINE_LIBRARY NAMES readline)

if(READLINE_LIBRARY)
    message(STATUS "Readline library found: ${READLINE_LIBRARY}")
    set(READLINE_FOUND TRUE)
else()
    message(FATAL_ERROR "Readline library not found")
endif()

# Include directories
include_directories(includes)

# Source files
file(GLOB_RECURSE SOURCE_FILES main.c helpers/*.c builtins/*.c execution/*.c parsing/*.c utils/*.c)

# Executable
add_executable(minibash ${SOURCE_FILES})

# Link readline library
target_link_libraries(minibash ${READLINE_LIBRARY})
