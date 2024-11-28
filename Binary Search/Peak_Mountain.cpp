#include <iostream>
#include <vector>
using namespace std;

int peakOfMountain(vector<int> &nums)
{
    int st = 1;
    int end = nums.size() - 2;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
        {
            return mid;
        }

        if (nums[mid - 1] < nums[mid])
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {0, 3, 8, 9, 5, 2};

    cout << peakOfMountain(nums) << endl;
    return 0;
}