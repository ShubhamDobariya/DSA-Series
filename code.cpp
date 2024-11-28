#include <iostream>
#include <vector>

using namespace std;

int reversArray(vector<int> &nums)
{
    int n = nums.size();

    int i = 0;
    int j = n - 1;

    while (i <= j)
    {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}

int printArray(vector<int> &nums)
{
    int n = nums.size();

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

bool isAlphaNum(char ch)
{
    if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
    {
        return true;
    }

    return false;
}

bool isPlindromeStr(string str)
{
    int n = str.size();

    int st = 0;
    int end = n - 1;

    while (st <= end)
    {
        if (!isAlphaNum(str[st]))
        {
            st++;
            continue;
        }

        if (!isAlphaNum(str[end]))
        {
            end--;
            continue;
        }

        if (tolower(str[st]) != tolower(str[end]))
        {
            return false;
        }

        st++;
        end--;
    }
    return true;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    // reversArray(nums);
    // printArray(nums);

    string str = "rac$eca#r";
    cout << isPlindromeStr(str) << endl;

    return 0;
}
