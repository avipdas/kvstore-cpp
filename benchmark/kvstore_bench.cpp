#include <benchmark/benchmark.h>
#include <future>
#include "../kvstore.h"

static void BM_ConcurrentPut(benchmark::State& state) {
  for (auto _ : state) {
    KVStore kv;

    auto put1 = std::async(std::launch::async, [&kv] {
      for (int i = 0; i < 100; ++i)
        kv.put("key" + std::to_string(i), "A");
    });

    auto put2 = std::async(std::launch::async, [&kv] {
      for (int i = 100; i < 200; ++i)
        kv.put("key" + std::to_string(i), "B");
    });

    put1.get();
    put2.get();
  }
}
BENCHMARK(BM_ConcurrentPut);

static void BM_ConcurrentGet(benchmark::State& state) {
  KVStore kv;
  for (int i = 0; i < 200; ++i)
    kv.put("key" + std::to_string(i), "val");

  for (auto _ : state) {
    auto get1 = std::async(std::launch::async, [&kv] {
      for (int i = 0; i < 100; ++i)
        benchmark::DoNotOptimize(kv.get("key" + std::to_string(i)));
    });

    auto get2 = std::async(std::launch::async, [&kv] {
      for (int i = 100; i < 200; ++i)
        benchmark::DoNotOptimize(kv.get("key" + std::to_string(i)));
    });

    get1.get();
    get2.get();
  }
}
BENCHMARK(BM_ConcurrentGet);

BENCHMARK_MAIN();
