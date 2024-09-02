#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sortElements(vector<int> &a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void printElements(vector<int> b, int n)
{
    for (int a = 0; a < n; a++)
    {
        cout << b[a] << " ";
    }
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
    sortElements(arr, size);
    printElements(arr, size);

    return 0;
}
