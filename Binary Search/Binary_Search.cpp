#include <iostream>
#include <vector>
using namespace std;

// Time complexity = O(lon n)
// space complexity = O(1)
int binarySearch(vector<int> &nums, int target)
{
    int st = 0;
    int end = nums.size() - 1;

    while (st <= end)
    {
        // int mid = (st + end) / 2; (totally correct)

        int mid = st + (end - st) / 2; // optimize for diff diff platform

        if (target > nums[mid])
        {
            st = mid + 1;
        }
        else if (target < nums[mid])
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

// Binary Search with recursion
// Time complexity = O(lon n)
// space complexity = O(log n)
int BSR(vector<int> &nums, int target, int st, int end)
{
    int mid = st + (end - st) / 2;

    if (st <= end)
    {
        if (target > nums[mid])
        {
            return BSR(nums, target, st = mid + 1, end);
        }
        else if (target < nums[mid])
        {
            return BSR(nums, target, st, end = mid - 1);
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {-1, 0, 3, 4, 5, 9, 12};
    int target = 12;
    int st = 0;
    int end = nums.size() - 1;

    cout << "Binary Search = " << binarySearch(nums, target) << endl;
    cout << "Binary Search using Recursion = " << BSR(nums, target, st, end) << endl;

    return 0;
}
