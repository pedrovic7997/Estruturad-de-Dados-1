cmake_minimum_required(VERSION 3.12)
project(EstGenLab C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(EstGenLab
        listagen.c
        listagen.h
        lponto.c
        lponto.h
        ponto.c)
