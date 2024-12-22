#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Leetcode : 15

// Brute force Approach
vector<vector<int>> bruteThreeSum(vector<int> &nums) // TC = O(n^3 * log(trip)) , SC = O(unique trip)
{
    int n = nums.size();
    vector<vector<int>> ans;

    set<vector<int>> s; // set<unique trip> // TC = log(unique trip)

    for (int i = 0; i < n; i++) // TC = O(n)
    {
        for (int j = i + 1; j < n; j++) // TC = O(n)
        {
            for (int k = j + 1; k < n; k++) // TC = O(n)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> trip = {nums[i], nums[j], nums[k]};
                    sort(trip.begin(), trip.end());

                    if (s.find(trip) == s.end()) // TC = log(unique trip)
                    {
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }
    return ans;
}

// Batter Approach using Hashing
// Logic = nums[i] or a + nums[j] or b + nums[k] or c = 0  ---> b+c = -a = target(0)
vector<vector<int>> batterThreeSum(vector<int> &nums) // Overall TC = O(n^2 * log(uniqueTrips)), SC = O(UniquesTrips + n)
{
    int n = nums.size();
    set<vector<int>> uniquetrips; // TC = O(log(uniquesTrip))

    for (int i = 0; i < n; i++) // TC = O(n)
    {
        int a = -nums[i];
        set<int> s;

        for (int j = i + 1; j < n; j++) // O(n)
        {
            int c = a - nums[j];

            if (s.find(c) != s.end()) // TC = log(unique trip)
            {
                vector<int> trip = {nums[i], nums[j], c};
                sort(trip.begin(), trip.end());
                uniquetrips.insert(trip);
            }

            s.insert(nums[j]);
        }
    }

    vector<vector<int>> ans(uniquetrips.begin(), uniquetrips.end());
    return ans;
}

// Optimied Approach(2 pointer Approach)

vector<vector<int>> optimizedThreeSum(vector<int> &nums) // overall TC = O(nlogn * n^2), SC = O(UniqueTrips)
{
    int n = nums.size();
    sort(nums.begin(), nums.end()); // TC = O(nlogn)

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) // TC = O(n)
    {
        int j = i + 1, k = n - 1;

        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        while (j < k) // TC = O(n)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum > 0)
            {
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++, k--;

                while (j < k && nums[j] == nums[j - 1])
                {
                    j++;
                }
            }
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
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    // vector<vector<int>> ans = bruteThreeSum(nums);
    // vector<vector<int>> ans = batterThreeSum(nums);
    vector<vector<int>> ans = optimizedThreeSum(nums);

    printVector(ans);
    return 0;
}