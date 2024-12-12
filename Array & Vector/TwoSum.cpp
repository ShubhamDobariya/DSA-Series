#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// LeetCode : 1

vector<int> BruteTwoSum(vector<int> &nums, int target) // Brute Force Approach || TC = O(n^2)
{
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }

    return ans;
}

vector<int> BetterTwoSum(vector<int> &nums, int target) // Better than brute force || Overall TC = O(n log n)
{
    int n = nums.size();
    vector<int> ans;

    sort(nums.begin(), nums.end()); // TC = O(n log n)

    int st = 0, end = n - 1;

    while (st <= end) // TC = O(n)
    {
        int sum = nums[st] + nums[end];

        if (sum == target)
        {
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        }
        else if (sum > target)
        {
            end--;
        }
        else
        {
            st++;
        }
    }

    return ans;
}

vector<int> OptimizedTwoSum(vector<int> &nums, int target) // Optimized Approach || Overall TC = O(n)
{
    int n = nums.size();

    vector<int> ans;
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++) // TC = O(n)
    {
        int first = nums[i];
        int second = target - first;

        if (m.find(second) != m.end()) // In hashing "m.find" TC = O(1)
        {
            ans.push_back(m[second]);
            ans.push_back(i);

            break;
        }

        m[first] = i;
    }

    return ans;
}

int printVector(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << endl;
    }
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // vector<int> ans = BruteTwoSum(nums, target);
    // vector<int> ans = BetterTwoSum(nums, target);
    vector<int> ans = OptimizedTwoSum(nums, target);
    printVector(ans);

    return 0;
}