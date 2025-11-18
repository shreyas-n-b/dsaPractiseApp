#include <iostream>
#include "utils.h"

int main() {
    auto v = generateRandomArray(10);
    for (int x : v) std::cout << x << ' ';
    std::cout << '\n';
    return 0;
}
