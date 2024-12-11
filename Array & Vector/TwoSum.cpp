#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// LeetCode : 1

vector<int> BruteTwoSum(vector<int> &nums, int target) // TC = O(n^2)
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
    vector<int> nums = {2, 11, 7, 15};
    int target = 9;

    vector<int> ans = BruteTwoSum(nums, target);
    printVector(ans);

    return 0;
}