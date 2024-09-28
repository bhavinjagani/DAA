#include <cstdlib>  
#include <iostream>
#include <vector>

void quicksort_random(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int pivot_idx = left + rand() % (right - left + 1);  
    int pivot = arr[pivot_idx];
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

    if (left < j) quicksort_random(arr, left, j);
    if (i < right) quicksort_random(arr, i, right);
}
int main() {
    std::vector<int> arr  = { 10, 7, 8, 9, 1, 5 };
    int n = arr.size();
    
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    quicksort_random(arr,0,n-1);
      
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}