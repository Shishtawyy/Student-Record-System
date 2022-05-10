cmake_minimum_required(VERSION 3.21)
project(Student_Record_System C)

set(CMAKE_C_STANDARD 99)

add_executable(Student_Record_System main.c interface.c interface.h program.c program.h data.h)
