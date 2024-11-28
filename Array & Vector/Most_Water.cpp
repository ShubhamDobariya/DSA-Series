#include <iostream>
#include <vector>
using namespace std;

// 2 pointer Approach  - O(n)
int maxWater(vector<int> &height)
{

    int left = 0;
    int right = height.size() - 1;

    int MaxWater = 0;

    while (left < right)
    {
        int width = right - left;
        int ht = min(height[left], height[right]);
        int currWater = width * ht;

        MaxWater = max(MaxWater, currWater);

        height[left] < height[right] ? left++ : right--;
    }

    return MaxWater;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max water = " << maxWater(height) << endl;
    return 0;
}