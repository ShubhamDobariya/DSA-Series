#include <iostream>
#include <vector>
using namespace std;

// Time complexity = O(log n)
int singleElement(vector<int> &nums)
{
    int n = nums.size();

    int st = 0;
    int end = n - 1;

    if (n == 1)
        return nums[0];

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (mid == 0 && nums[0] != nums[1])
            return nums[mid];

        if (mid == n - 1 && nums[n - 1] != nums[n - 2])
            return nums[mid];

        if (nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid])
            return nums[mid];

        if (mid % 2 == 0)
        { // even case
            if (nums[mid - 1] == nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else
        { // odd case
            if (nums[mid - 1] == nums[mid])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    vector<int> num = {3, 3, 7, 7, 10, 11, 11};

    cout << "Even case = " << singleElement(nums) << endl;
    cout << "Odd case = " << singleElement(num) << endl;
    return 0;
}