#include <iostream>
#include <vector>

using namespace std;

// Leetcode 287 (This problem is solved by linked list concept)

int findDuplicateNumber(vector<int> &nums) // Overall TC = O(n) + O(n) = O(n)
{
    int slow = nums[0];
    int fast = nums[0];

    do // TC = O(n)
    {
        slow = nums[slow];       // Increase by 1
        fast = nums[nums[fast]]; // Increase by 2
    } while (slow != fast);

    slow = nums[0];

    while (slow != fast) // TC = O(n)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow; // We can return fast or slow because both are equal
}

int main()
{
    vector<int> nums = {3, 1, 3, 4, 2};

    cout << findDuplicateNumber(nums) << endl;
    return 0;
}