#include <iostream>
#include <vector>

using namespace std;

int sortArray0s1s2s(vector<int> &nums)
{
    int n = nums.size();

    int mid = 0;
    int low = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int printarray(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};
    sortArray0s1s2s(nums);
    printarray(nums);
    return 0;
}