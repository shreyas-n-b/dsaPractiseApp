#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <vector>
#include <string>

// Benchmark for sorting algorithms
void benchmarkSort(
    void (*sortFunc)(std::vector<int>&),
    const std::string& algoName,
    const std::vector<int>& nValues,
    int repetitions
);

#endif // BENCHMARK_H
