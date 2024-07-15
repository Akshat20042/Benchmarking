cmake_minimum_required(VERSION 3.10)
project(MatrixMultiplicationBenchmark)

set(CMAKE_CXX_STANDARD 14)

# Add benchmark library
add_subdirectory(libs/benchmark)

# Add source files
add_executable(main src/main.cpp src/matrix_multiply.cpp)

# Link benchmark library
target_link_libraries(main benchmark::benchmark)
