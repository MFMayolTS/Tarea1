cmake_minimum_required(VERSION 3.21)
project(Structs_Files C)

set(CMAKE_C_STANDARD 99)

add_executable(Structs_Files main.c Personas.h Personas.c)
