#include "matrix_multiply.h"
#include <thread>
#include <vector>

// Standard matrix multiply function
void matrix_multiply(const std::vector<std::vector<int>>& A, 
                     const std::vector<std::vector<int>>& B, 
                     std::vector<std::vector<int>>& C, 
                     int N) 
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Threaded matrix multiply function
void matrix_multiply(const std::vector<std::vector<int>>& A, 
                     const std::vector<std::vector<int>>& B, 
                     std::vector<std::vector<int>>& C, 
                     int N, int num_threads) 
{
    std::vector<std::thread> threads;
    int chunk_size = N / num_threads;

    for (int t = 0; t < num_threads; ++t) {
        threads.emplace_back([&, t]() {
            for (int i = t * chunk_size; i < (t + 1) * chunk_size; ++i) {
                for (int j = 0; j < N; ++j) {
                    C[i][j] = 0;
                    for (int k = 0; k < N; ++k) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }
}
