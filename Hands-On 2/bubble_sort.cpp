#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n)
{
    int i, j;
    bool swapElement;
    for (i = 0; i < n - 1; i++) {
        swapElement = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapElement = true;
            }
        }
        if (swapElement == false)
            break;
    }
}

void printArrayElement(vector<int> arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << " " << arr[i];
}

int main()
{
    int size;
    cout << "Enter the number of elements:";
    cin >> size;
    vector<int> arr(size);
    cout << "Enter " << size << " Element:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
    bubbleSort(arr, size);
    cout << "Sorted array Using Bubble Sort:: \n";
    printArrayElement(arr, size);
    return 0;
}

