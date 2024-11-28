#include <iostream>
#include <vector>
using namespace std;

// Brute force approach solution
vector<int> pairSum(vector<int> nums, int target) // TC = O(n^2)
{
    vector<int> ans;
    int n = nums.size();

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

// 2 pointer approach solution
vector<int> pairSum2(vector<int> nums, int target) // TC = O(n)
{
    vector<int> ans;
    int n = nums.size();

    int i = 0, j = n - 1;

    while (i < j)
    {
        int ps = nums[i] + nums[j];

        if (ps > target)
        {
            j--;
        }
        else if (ps < target)
        {
            i++;
        }
        else
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 13;

    // vector<int> ans = pairSum(nums, target);
    vector<int> ans = pairSum2(nums, target);
    cout << ans[0] << ", " << ans[1] << endl;

    return 0;
}