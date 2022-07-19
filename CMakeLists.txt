cmake_minimum_required(VERSION 3.22)

project(get_next_line C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

SET ( CMAKE_C_COMPILER "cc" )

ADD_COMPILE_OPTIONS (cc -Wall -Wextra -Werror -D BUFFER_SIZE=42)

add_executable(get_next_line
        get_next_line.c
        get_next_line.h
        get_next_line_utils.c
        main.c)
