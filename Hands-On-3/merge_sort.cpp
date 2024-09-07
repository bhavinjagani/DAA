#include <bits/stdc++.h>
using namespace std; 

void mergeArray(int arr[], int l,int mid, int r)
{
    int Lsize = mid - l + 1;
    int Rsize = r - mid;
    int Left[Lsize], Right[Rsize];

    for (int i = 0; i < Lsize; i++)
    {
        Left[i] = arr[l + i];
    }
    for (int j = 0; j < Rsize; j++)
    {    
        Right[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0;
    int k = l;
    while (i < Lsize && j < Rsize) {
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        }
        else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < Lsize) {
        arr[k] = Left[i];
        i++;
        k++;
    }
    while (j < Rsize) {
        arr[k] = Right[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
       return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    mergeArray(arr, l, mid, r);
}

void printVector(int arr[],int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {5,2,4,7,1,3,2,6};
    int size = 7;
    cout << "Given Input Array \n";
    printVector(arr,size);
    mergeSort(arr, 0,size);
    cout << "Sorted Output Array \n";
    printVector(arr,size);
    return 0;
}
