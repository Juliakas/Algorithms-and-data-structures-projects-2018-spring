cmake_minimum_required(VERSION 3.10)
project(Aerouostas C)

set(CMAKE_C_STANDARD 99)

add_executable(Aerouostas main.c planesModel.h priorityQueue/pqueue.c priorityQueue/pqueue.h bigint/Arithmetic.c bigint/Arithmetic.h bigint/Bigint.c bigint/Bigint.h)