#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickselect(vector<int>& arr, int low, int high, int i) {
    if (low == high) {
        return arr[low];
    }
    
    int pivotIndex = partition(arr, low, high);
    
    if (pivotIndex == i) {
        return arr[pivotIndex];
    } else if (pivotIndex > i) {
        return quickselect(arr, low, pivotIndex - 1, i);
    } else {
        return quickselect(arr, pivotIndex + 1, high, i);
    }
}

int find_ith_statistic(vector<int>& arr, int i) { 
    return quickselect(arr, 0, arr.size() - 1, i - 1);
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    cout<<"Input Array:"<<endl;
       for (int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    int i = 3;  
        int result = find_ith_statistic(arr, i);
        cout <<endl<< "The " << i << "rd smallest element is " << result << endl;
   
    return 0;
}
