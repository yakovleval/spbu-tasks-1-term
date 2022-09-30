cmake_minimum_required(VERSION 3.16)
project(2.1 C)

set(CMAKE_C_STANDARD 99)

add_executable(2.1 src/main.c src/solution.c)
add_executable(tests tests/tests.c tests/runTests.c CuTestLib/CuTest.c src/solution.c)