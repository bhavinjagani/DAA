#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    if (nums.size() == 1)
    {
        return nums.size();
    }
    while (i < nums.size() - 1)
    {
        if (nums[i] == nums[i + 1])
        {
            nums.erase(nums.begin() + i);
        }
        else
        {
            i++;
        }
    }

    return nums.size();
}
int main()
{
    vector<int> a = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int i;
    cout << "Inputed Arrays:" << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    removeDuplicates(a);
    cout <<endl<< "Final Array:";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}