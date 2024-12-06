#include <iostream>
#include <vector>
using namespace std;

// Leetcode = 54
vector<int> spiralOrder(vector<vector<int>> &mat) // TC = O(m * n)
{
    int row = mat.size(), column = mat[0].size();

    vector<int> ans;

    int srow = 0, erow = row - 1;
    int scol = 0, ecol = column - 1;

    while (srow <= erow && scol <= ecol)
    {
        // Top
        for (int j = scol; j <= ecol; j++)
        {
            ans.push_back(mat[srow][j]);
        }

        // Right
        for (int i = srow + 1; i <= erow; i++)
        {
            ans.push_back(mat[i][ecol]);
        }

        // Bottom
        for (int j = ecol - 1; j >= scol; j--)
        {
            if (srow == erow)
            {
                break;
            }
            ans.push_back(mat[erow][j]);
        }

        // Left
        for (int i = erow - 1; i >= srow + 1; i--)
        {
            if (scol == ecol)
            {
                break;
            }
            ans.push_back(mat[i][scol]);
        }

        srow++, erow--, scol++, ecol--;
    }

    return ans;
}

int printEle(vector<int> ans)
{
    int n = ans.size();

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    vector<int> ans = spiralOrder(matrix);

    printEle(ans);

    return 0;
}