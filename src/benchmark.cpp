#include "benchmark.h"
#include "utils.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <numeric>
#include <cmath>

using namespace std;

// --------------------------------------------------------
// Benchmark Sorting Algorithms  (SKELETON ONLY)
// --------------------------------------------------------
void benchmarkSort(
    void (*sortFunc)(vector<int>&),
    const string& algoName,
    const vector<int>& nValues,
    int repetitions
) {
    // CSV file path
    string filename = "results/" + algoName + "_summary.csv";

    // Open CSV file
    ofstream fout(filename);
    fout << "n,avg_time_ms,stddev_ms\n";

    // LOOP OVER DIFFERENT ARRAY SIZES
    for (int n : nValues) {

        // stores times for R repetitions
        vector<double> times;

        // REPEAT SORTING R TIMES
        for (int r = 0; r < repetitions; r++) {

            // STEP 1 → generate random array
            vector<int> arr = generateRandomArray(n);

            // STEP 2 → measure start time
            auto start = chrono::high_resolution_clock::now();

            // STEP 3 → execute sorting function
            sortFunc(arr);

            // STEP 4 → measure end time
            auto end = chrono::high_resolution_clock::now();

            // STEP 5 → calculate duration in ms
            double ms = chrono::duration<double, milli>(end - start).count();
            times.push_back(ms);
        }

        // STEP 6 → calculate average
        double avg = accumulate(times.begin(), times.end(), 0.0) / times.size();

        // STEP 7 → calculate standard deviation
        double sumSq = 0;
        for (double t : times) {
            sumSq += (t - avg) * (t - avg);
        }
        double stddev = sqrt(sumSq / times.size());

        // STEP 8 → write a CSV row
        fout << n << "," << avg << "," << stddev << "\n";
    }

    fout.close();

    cout << "Benchmark completed for: " << algoName << endl;
}
