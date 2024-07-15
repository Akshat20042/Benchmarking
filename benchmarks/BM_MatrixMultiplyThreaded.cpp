#include <benchmark/benchmark.h>
#include "matrix_multiply.h"
#include <vector>
#include <thread>

static void BM_MatrixMultiplyThreaded(benchmark::State& state) {
    const int N = static_cast<int>(state.range(0));
    const int num_threads = std::thread::hardware_concurrency();
    std::vector<std::vector<int>> A(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> B(N, std::vector<int>(N, 2));
    std::vector<std::vector<int>> C(N, std::vector<int>(N, 0));

    for (auto _ : state) {
        matrix_multiply(A, B, C, N, num_threads);
    }

    benchmark::DoNotOptimize(C);
}

BENCHMARK(BM_MatrixMultiplyThreaded);
