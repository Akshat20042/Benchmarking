#include <benchmark/benchmark.h>

// Benchmark declarations
void BM_MatrixMultiply(benchmark::State& state);
void BM_MatrixMultiplyThreaded(benchmark::State& state);

// Register the benchmarks
BENCHMARK(BM_MatrixMultiply)->RangeMultiplier(2)->Range(16, 128);
BENCHMARK(BM_MatrixMultiplyThreaded)->RangeMultiplier(2)->Range(16, 128);

// Main function
BENCHMARK_MAIN();
