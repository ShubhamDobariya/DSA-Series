#include <iostream>
using namespace std;

int PowOfTwo(int n)
{
    if (n <= 0)
    {
        return false;
    }

    while (n % 2 == 0)
    {
        n /= 2;
    }
    if (n == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int result1 = PowOfTwo(32);
    cout << result1 << endl;

    int result2 = PowOfTwo(3);
    cout << result2 << endl;
    return 0;
}