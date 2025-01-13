#include <iostream>

using namespace std;

// LeetCode : 509
int FibonacciNum(int n) // TC = O(2^n) , SC = O(n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return FibonacciNum(n - 1) + FibonacciNum(n - 2);
}

int main()
{
    int n = 4;
    cout << FibonacciNum(n) << endl;
    return 0;
}
