#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &A)
{
    // step : 1 => find pivot
    int n = A.size();
    int pivot = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            pivot = i;
            break;
        }
    }

    if (pivot == -1)
    {
        reverse(A.begin(), A.end()); // inplace change
        return;
    }

    // step : 2 => find right most element

    for (int i = n - 1; i > pivot; i--)
    {
        if (A[i] > A[pivot])
        {
            swap(A[i], A[pivot]);
            break;
        }
    }

    // step : 3 => reverse ((pivot + 1) to n-1)

    int i = pivot + 1;
    int j = n - 1;

    while (i <= j)
    {
        swap(A[i], A[j]);
        i++;
        j--;
    }
}

int printArray(vector<int> &A)
{
    int n = A.size() - 1;

    for (int i = 0; i <= n; i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{
    vector<int> A = {1, 2, 3, 6, 5, 4};
    nextPermutation(A);
    printArray(A);
    return 0;
}