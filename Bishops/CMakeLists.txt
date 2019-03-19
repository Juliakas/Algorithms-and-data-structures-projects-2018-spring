# cmake_minimum_required(VERSION <specify CMake version here>)
project(Bishops C)

set(CMAKE_C_STANDARD 99)

add_executable(Bishops bishopZones.c chess.h chess.c bishop.h bishop.c)