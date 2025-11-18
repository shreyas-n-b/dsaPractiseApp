#include "utils.h"
#include <random>
#include <vector>
#include <chrono>

// single RNG for the whole program
static std::mt19937 rng((unsigned)std::chrono::high_resolution_clock::now().time_since_epoch().count());

std::vector<int> generateRandomArray(int n, int maxValue) {
    std::uniform_int_distribution<int> dist(0, maxValue);
    std::vector<int> arr;
    arr.reserve(n);
    for (int i = 0; i < n; ++i) arr.push_back(dist(rng));
    return arr;
}
