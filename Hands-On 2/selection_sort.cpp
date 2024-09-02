#include <bits/stdc++.h>
using namespace std;

void swapElement(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionsort(vector<int> &arr, int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;

        swapElement(arr[min], arr[i]);
    }
}

void printElements(vector<int> arr, int s)
{
    int i;
    cout << endl;
    for (i = 0; i < s; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;
    vector<int> arr(size);
    cout << "Enter " << size << " Element:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
    selectionsort(arr, size);
    cout << endl;
    cout << "Sorted array Using Selection Sort: ";
    printElements(arr, size);
}
