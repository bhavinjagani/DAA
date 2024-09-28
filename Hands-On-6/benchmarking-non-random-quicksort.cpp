#include <iostream>
#include <vector>
#include <algorithm>  
#include <chrono>     
#include <cstdlib>


void quicksort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2];  
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) quicksort(arr, left, j);
    if (i < right) quicksort(arr, i, right);
}


std::vector<int> best_case(int n) {
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = i;
    return arr;
}


std::vector<int> worst_case(int n) {
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = n - i;
    return arr;
}


std::vector<int> average_case(int n) {
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = rand() % n;  
    return arr;
}


void benchmark() {
    std::vector<int> input_sizes = {100, 1000, 5000, 10000, 20000, 50000};  

    for (int n : input_sizes) {
        
        std::vector<int> arr = best_case(n);
        auto start = std::chrono::high_resolution_clock::now();
        quicksort(arr, 0, n - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> best_time = end - start;
        std::cout << "Best case (n=" << n << "): " << best_time.count() << " seconds\n";

        
        arr = worst_case(n);
        start = std::chrono::high_resolution_clock::now();
        quicksort(arr, 0, n - 1);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> worst_time = end - start;
        std::cout << "Worst case (n=" << n << "): " << worst_time.count() << " seconds\n";

        
        arr = average_case(n);
        start = std::chrono::high_resolution_clock::now();
        quicksort(arr, 0, n - 1);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> avg_time = end - start;
        std::cout << "Average case (n=" << n << "): " << avg_time.count() << " seconds\n";
    }
}

int main() {
    srand(time(0));  
    benchmark();
    return 0;
}
