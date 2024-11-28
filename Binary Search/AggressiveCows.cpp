#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isPossible(vector<int> &arr, int N, int C, int minAllowedDist) // O(N)
{
    int cow = 1;
    int lastStallPos = arr[0];

    for (int i = 0; i < N; i++)
    {
        if (arr[i] - lastStallPos >= minAllowedDist)
        {
            cow++;
            lastStallPos = arr[i];
        }
        if (cow == C)
        {
            return true;
        }
    }
    return false;
}

int getDistance(vector<int> &arr, int N, int C)
{
    sort(arr.begin(), arr.end()); // O(NlogN)
    int st = 1;
    int end = arr[N - 1] - arr[0];
    int ans = -1;

    while (st <= end) // Overall O(log(range) * N)
    {
        int mid = st + (end - st) / 2;

        if (isPossible(arr, N, C, mid))
        {
            ans = mid;
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 8, 4, 9};
    int N = 5;
    int C = 3;

    cout << getDistance(arr, N, C) << endl;
    return 0;
}