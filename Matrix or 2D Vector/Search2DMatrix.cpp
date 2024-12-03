#include <iostream>
#include <vector>

using namespace std;

// Leetcode Qs. 74

bool searchInRow(vector<vector<int>> mat, int target, int Row) // TC = O(log(n)) , n = column
{
    int column = mat[0].size();
    int st = 0, end = column - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (target == mat[Row][mid])
        {
            return true;
        }
        else if (target > mat[Row][mid])
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return false;
}

bool searchMatrix(vector<vector<int>> mat, int target) // TC = O(log(m)), m = Row ||  So, overall "TC = O(log(m*n))"
{
    int row = mat.size(), column = mat[0].size();

    int startRow = 0, endRow = row - 1;

    while (startRow <= endRow)
    {
        int midRow = startRow + (endRow - startRow) / 2;

        if (mat[midRow][0] <= target && target <= mat[midRow][column - 1])
        {
            // found row ----> apply BS again on that Row
            return searchInRow(mat, target, midRow);
        }
        else if (target >= mat[midRow][0])
        {
            // down --> right
            startRow = midRow + 1;
        }
        else
        {
            // up --> left
            endRow = midRow - 1;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 34;

    cout << searchMatrix(matrix, target) << endl;
    return 0;
}