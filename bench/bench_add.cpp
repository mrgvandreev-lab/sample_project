#include <benchmark/benchmark.h>
#include "add.hpp"

static void BM_Add(benchmark::State &state)
{
    int a = 3;
    int b = 5;
    for (auto _ : state) {
        benchmark::DoNotOptimize(a);
        benchmark::DoNotOptimize(b);
        benchmark::DoNotOptimize(add(a, b));
    }
}
BENCHMARK(BM_Add);

BENCHMARK_MAIN();
