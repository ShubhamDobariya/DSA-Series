#include <iostream>
#include <vector>

using namespace std;

int merge2SortedArr(vector<int> &A, vector<int> &B, int m, int n)
{
    int idx = m + n - 1;
    int i = m - 1;
    int j = n - 1;

    while (i >= 0 && j >= 0)
    {
        if (A[i] >= B[j])
        {
            A[idx] = A[i];
            idx--;
            i--;
        }
        else
        {
            A[idx] = B[j];
            idx--;
            j--;
        }
    }

    while (j >= 0)
    {
        A[idx] = B[j];
        idx--;
        j--;
    }
}

int printArray(vector<int> &A, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{
    vector<int> A = {1, 2, 3, 0, 0, 0};
    int m = 3;
    int size = 6;

    vector<int> B = {2, 5, 6};
    int n = 3;

    merge2SortedArr(A, B, m, n);
    printArray(A, size);
    return 0;
}