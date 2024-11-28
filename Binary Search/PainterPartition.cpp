#include <iostream>
#include <vector>
using namespace std;

int isPossible(vector<int> &nums, int n, int m, int maxAllowedTime) // O(n)
{
    int painter = 1;
    int time = 0;

    for (int i = 0; i < n; i++)
    {
        if (time + nums[i] <= maxAllowedTime)
        {
            time += nums[i];
        }
        else
        {
            painter++;
            time = nums[i];
        }
    }

    return painter <= m;
}

int minTimeToPaint(vector<int> &nums, int n, int m)
{
    int sum = 0;
    int maxVal = INT32_MIN;

    for (int i = 0; i < n; i++) // O(n)
    {
        sum += nums[i];
        maxVal = max(maxVal, nums[i]);
    }

    int st = maxVal;
    int end = sum;
    int ans = -1;

    while (st <= end) // O(log (sum) * n)  ---> overall Time complexity
    {
        int mid = st + (end - st) / 2;

        if (isPossible(nums, n, m, mid))
        { // true
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {40, 30, 10, 20};
    int n = nums.size();
    int m = 2;
    cout << minTimeToPaint(nums, n, m) << endl;
    return 0;
}