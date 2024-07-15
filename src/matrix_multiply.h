#ifndef MATRIX_MULTIPLY_H
#define MATRIX_MULTIPLY_H

#include <vector>

void matrix_multiply(const std::vector<std::vector<int>>& A, 
                     const std::vector<std::vector<int>>& B, 
                     std::vector<std::vector<int>>& C, 
                     int N);

void matrix_multiply(const std::vector<std::vector<int>>& A, 
                     const std::vector<std::vector<int>>& B, 
                     std::vector<std::vector<int>>& C, 
                     int N, int num_threads);

#endif // MATRIX_MULTIPLY_H
