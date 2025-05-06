#include <benchmark/benchmark.h>
#include "../kvstore.h"

static void BM_Put(benchmark::State& state) {
  KVStore kv;
  for (auto _ : state) {
    kv.put("key", "value");
  }
}
BENCHMARK(BM_Put);

static void BM_Get(benchmark::State& state) {
  KVStore kv;
  kv.put("key", "value");
  for (auto _ : state) {
    benchmark::DoNotOptimize(kv.get("key"));
  }
}
BENCHMARK(BM_Get);

static void BM_Remove(benchmark::State& state) {
  for (auto _ : state) {
    KVStore kv;
    kv.put("key", "value");
    kv.remove("key");
  }
}
BENCHMARK(BM_Remove);

BENCHMARK_MAIN();
