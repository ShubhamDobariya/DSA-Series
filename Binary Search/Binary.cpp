#include <iostream>
using namespace std;

int DecimalToBinary(int decimal)
{
    int ans = 0;
    int pow = 1;

    while (decimal > 0)
    {
        int remainder = decimal % 2;
        decimal = decimal / 2;

        ans += (remainder * pow);
        pow *= 10;
    }
    return ans;
}

int BinaryToDecimal(int binary)
{
    int ans = 0;
    int pow = 1;

    while (binary > 0)
    {
        int remainder = binary % 2;
        binary = binary / 10;

        ans += remainder * pow;
        pow *= 2;
    }
    return ans;
}

int main()
{
    int Binary = DecimalToBinary(10);
    cout << "Binary of 10 is: " << Binary << endl;

    int Decimal = BinaryToDecimal(1010);
    cout << "Decimal of 1010 is: " << Decimal << endl;
    return 0;
}
