#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrays(vector<vector<int>> &a)
{
    vector<int> result;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            result.push_back(a[i][j]);
        }
        for (int i = 1; i < result.size(); i++)
        {
            int key = result[i];
            int j = i - 1;
            while (j >= 0 && result[j] > key)
            {
                result[j + 1] = result[j];
                j = j - 1;
            }
            result[j + 1] = key;
        }
    }
    return result;
}

int main()
{

    int K, N;
      vector<vector<int>> v= {
        {1, 3, 7},  
        {2, 4, 8},   
        {9, 10, 11}  
    };
   
    cout<<"Inputed Arrays:"<<endl;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
          cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<int> sortedArray = sortArrays(v);
    cout << "Sorted Array :";
    for (int j = 0; j < sortedArray.size(); j++)
    {
        cout << sortedArray[j]<<" ";
    }
    return 0;
}