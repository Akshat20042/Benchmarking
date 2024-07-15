#include <benchmark/benchmark.h>
#include "matrix_multiply.h"
#include <vector>

static void BM_MatrixMultiply(benchmark::State& state) {
    const int N = static_cast<int>(state.range(0));
    std::vector<std::vector<int>> A(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> B(N, std::vector<int>(N, 2));
    std::vector<std::vector<int>> C(N, std::vector<int>(N, 0));
    
    for (auto _ : state) {
        matrix_multiply(A, B, C, N);
    }
}

BENCHMARK(BM_MatrixMultiply);
