#include <iostream>
using namespace std;

int main()
{
    int nums[] = {24, 36, 56, 12, 10, 43};
    int size = 6;

    int smallest = INT16_MAX;
    int largest = INT16_MIN;

    for (int i = 0; i < size; i++)
    {
        // if (nums[i] < smallest)
        // {
        //     smallest = nums[i];
        // }

        smallest = min(nums[i], smallest);
        largest = max(nums[i], largest);
    }

    cout << "smallest value : " << smallest << endl;
    cout << "largest value : " << largest << endl;

    return 0;
}