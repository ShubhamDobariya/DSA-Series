#include <iostream>
#include <vector>
using namespace std;

// Qs - Product of array except self - O(n^2)
vector<int> ProductOfArray(vector<int> &nums)
{

    vector<int> ans(nums.size(), 1);

    for (int i = 0; i < nums.size(); i++)
    {

        for (int j = 0; j < nums.size(); j++)
        {
            if (i != j)
            {
                ans[i] *= nums[j];
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = ProductOfArray(nums);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    ;

    return 0;
}