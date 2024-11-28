#include <iostream>
#include <vector>
using namespace std;

// using Kadane's Algorithm
int maxSubArrSum(vector<int> &nums) // Tc = O(n)
{
    int n = nums.size();
    int currSum = 0;
    int maxSum = INT32_MIN;

    for (int i = 0; i <= n; i++)
    {
        currSum += nums[i];
        maxSum = max(currSum, maxSum);

        if (currSum < 0)
        {
            currSum = 0;
        }
    }

    return maxSum;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};

    cout << maxSubArrSum(nums) << endl;
    return 0;
}