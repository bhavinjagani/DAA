#include <iostream>
using namespace std;

void sortElements(int a[], int n)
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

void printElements(int b[], int n)
{
    for (int a = 0; a < n; a++)
    {
        cout << b[a] << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
}

int main()
{
    int arr[] = {17, 15, 10, 24, 33, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortElements(arr, n);
    printElements(arr, n);

    return 0;
}
