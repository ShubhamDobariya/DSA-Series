#include <iostream>
#include <vector>

using namespace std;

// Leetcode - 240

bool searchMatrix(vector<vector<int>> mat, int target) // TC = O(n + m), because row = 0 ----> m(row++) and column = n-1 ----> 0(column--)
{
    int m = mat.size(), n = mat[0].size();

    int row = 0, column = n - 1;

    while (column >= 0 && row < m)
    {
        if (target == mat[row][column])
        {
            return true;
        }
        else if (target < mat[row][column])
        {
            column--;
        }
        else
        {
            row++;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 5;

    cout << searchMatrix(matrix, target) << endl;

    return 0;
}