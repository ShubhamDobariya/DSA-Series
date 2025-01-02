#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Leetcode : 560
// Brute force Approach
int bruteSubarrySum(vector<int> &nums, int target) // TC = O(n^2) , SC = O(1)
{
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) // starting point // TC = O(n)
    {
        int sum = 0;
        for (int j = i; j < n; j++) // ending point// TC = O(n)
        {
            sum += nums[j];

            if (sum == target)
            {
                count++;
            }
        }
    }

    return count;
}

// Most Optimized Approach
// here we use unordered_map because it's TC = O(1) in practical case and In map, it's use internally tree data structure So TC = (log n)
int optSubarraySum(vector<int> &nums, int target) // TC = O(n) , SC = O(n)
{
    int n = nums.size();
    int count = 0;
    vector<int> prefixSum(n, 0); // Beacuse of this SC = O(n)

    prefixSum[0] = nums[0];
    for (int i = 1; i < n; i++) // TC = O(n)
    {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    unordered_map<int, int> m;  // Beacuse of this SC = O(n)
    for (int j = 0; j < n; j++) // TC = O(n)
    {
        if (prefixSum[j] == target)
        {
            count++;
        }

        int value = prefixSum[j] - target;

        if (m.find(value) != m.end())
        {
            count += m[value];
        }

        if (m.find(prefixSum[j]) == m.end())
        {
            m[prefixSum[j]] = 0;
        }
        m[prefixSum[j]]++;
    }

    return count;
}

int main()
{
    vector<int> nums = {9, 4, 20, 3, 10, 5};
    int target = 33;

    // cout << bruteSubarrySum(nums, target) << endl;
    cout << optSubarraySum(nums, target) << endl;
    return 0;
}