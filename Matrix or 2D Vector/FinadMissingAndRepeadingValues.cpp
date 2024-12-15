#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// LeetCode 2965

vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) // TC = O(n^2)
{
    int n = grid.size();
    vector<int> ans;
    unordered_set<int> s;
    int a, b;
    int expSum = 0, actualSum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            actualSum += grid[i][j];
            if (s.find(grid[i][j]) != s.end())
            {
                a = grid[i][j];
                ans.push_back(a);
            }

            s.insert(grid[i][j]);
        }
    }

    expSum = (n * n) * (n * n + 1) / 2;
    b = expSum + a - actualSum;
    ans.push_back(b);

    return ans;
}

int printVector(vector<int> &ans)
{
    int n = ans.size();

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
}

int main()
{
    vector<vector<int>> grid = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};

    vector<int> ans = findMissingAndRepeatedValues(grid);

    printVector(ans);
    return 0;
}
