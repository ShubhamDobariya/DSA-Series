#include <iostream>
using namespace std;

int selectionSort(int arr[], int n) // O(n^2)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallidx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallidx])
            {
                smallidx = j;
            }
        }

        swap(arr[i], arr[smallidx]);
    }
}

int printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {4, 1, 5, 2, 3};
    int n = 5;

    selectionSort(arr, n);
    printarray(arr, n);
    return 0;
}