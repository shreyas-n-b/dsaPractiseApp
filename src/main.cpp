#include <iostream>
#include <vector>
#include "benchmark.h"
#include "sorting.h"

using namespace std;

int main() 
{
    vector<int> sizes = {1000, 5000, 10000, 20000};  // n values
    int reps = 5;                                    // repetitions

    cout << "Sorting Benchmarks\n";
    cout << "------------------\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Merge Sort\n";
    cout << "3. Quick Sort\n";
    cout << "4. Exit\n";

    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) 
    {
        case 1:
            benchmarkSort(bubbleSort, "bubble", sizes, reps);
            break;
        case 2:
            benchmarkSort(mergeSort, "merge", sizes, reps);
            break;
        case 3:
            benchmarkSort(quickSort, "quick", sizes, reps);
            break;
        default:
            cout << "Exiting...\n";
            return 0;
    }

    return 0;
}
