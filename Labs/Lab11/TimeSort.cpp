#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <chrono>    // For high-resolution timing
#include <random>    // To generate test data

using namespace std;
using namespace std::chrono;

// 1. Manual Sort Function (Bubble Sort - O(N^2))
void manualSort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of integers (try 5000 for a clear time difference): ";
    cin >> n;

    // Generate random data to ensure a fair test
    vector<int> original;
    for (int i = 0; i < n; i++) {
        original.push_back(rand() % 10000);
    }

    // Create two copies for the two different methods
    vector<int> vec1 = original;
    vector<int> vec2 = original;

    // --- Method 1: Manual Sort ---
    auto start1 = high_resolution_clock::now();
    manualSort(vec1);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    // --- Method 2: STL Sort ---
    auto start2 = high_resolution_clock::now();
    sort(vec2.begin(), vec2.end());
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    // Results
    cout << "\n--- Results ---" << endl;
    cout << "Manual Sort Time: " << duration1.count() << " microseconds" << endl;
    cout << "STL Sort Time:    " << duration2.count() << " microseconds" << endl;
    
    if (duration2.count() > 0) {
        cout << "STL is approximately " << duration1.count() / duration2.count() << "x faster!" << endl;
    }

    return 0;
}