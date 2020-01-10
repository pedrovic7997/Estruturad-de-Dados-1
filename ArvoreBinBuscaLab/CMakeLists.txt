cmake_minimum_required(VERSION 3.12)
project(ABBLab C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ABBLab
        abb.h abb.c testadorArvore.c)
