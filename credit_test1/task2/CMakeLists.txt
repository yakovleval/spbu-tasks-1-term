cmake_minimum_required(VERSION 3.24)
project(task2 C)

set(CMAKE_C_STANDARD 99)

add_executable(task2 ../../hw6/6.3/mergesort.c ../../hw6/6.3/product.c main.c)
