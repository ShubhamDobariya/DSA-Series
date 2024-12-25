#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Leetcode : 18
// Most Optimied Approach(2 pointer Approach)
vector<vector<int>> fourSum(vector<int> &nums) // Overall TC = O(nlogn * n^3), SC = O(uniquegroup)
{
    int n = nums.size();
    vector<vector<int>> ans; // vector<uniquegroup>

    sort(nums.begin(), nums.end()); // TC = O(nlong)

    for (int i = 0; i < n; i++) // TC = O(n)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n;) // TC = O(n)
        {
            int p = j + 1, q = n - 1;

            while (p < q) // TC = O(n)
            {
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];

                if (sum < 0)
                {
                    p++;
                }
                else if (sum > 0)
                {
                    q--;
                }
                else
                {
                    ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                    p++;
                    q--;

                    while (p < q && nums[p] == nums[p - 1])
                        p++;
                }
            }
            j++;
            while (j < n && nums[j] == nums[j - 1])
                j++;
        }
    }

    return ans;
}

int printVector(vector<vector<int>> &ans)
{
    int n = ans.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> nums = {-2, -1, -1, 1, 1, 2, 2};

    vector<vector<int>> ans = fourSum(nums);
    printVector(ans);

    return 0;
}