cmake_minimum_required(VERSION 3.9)
project(Ketvirta)

set(CMAKE_CXX_STANDARD 11)

add_executable(Ketvirta
        bigint.c
        bigint.h
        main.c cmake-build-debug/ Arithmetic.c Arithmetic.h)
