#include <iostream>
using namespace std;

bool isFreqSame(int freq1[], int freq2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
        {
            return false;
        }
    }
    return true;
}

bool permutationString(string s1, string s2)
{
    int freq[26] = {0};

    for (int i = 0; i < s1.length(); i++)
    {
        // int idx = s1[i] - 'a';
        // freq[idx]++;

        freq[s1[i] - 'a']++; // it's short form to write a code
    }

    int windSize = s1.length(); // s1 --> 2

    for (int i = 0; i < s2.length(); i++)
    {
        int windIdx = 0; // initialize windIdx with 0
        int idx = i;     // initialize s2 idx with i that means i = 0 then idx is also 0
        int windFreq[26] = {0};

        while (windIdx < windSize && idx < s2.length())
        // iteration - 1 : 0 < 2(true) && 0 < s2.length(true)
        // iteration - 2 : 1 < 2(true) && 1 < s2.length(true)
        // iteration - 3 : 3 < 2(false) && 1 < s2.length(true) --> stop the while loop
        {
            windFreq[s2[idx] - 'a']++; // in windFreq array a(97) - e(101) = 4 idx which is crease by 1
            windIdx++;                 // increase windIdx by 1
            idx++;                     // increase s2 idx by 1
        }

        if (isFreqSame(freq, windFreq))
        {
            return true;
        }
    }
}

int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";

    cout << permutationString(s1, s2) << endl;
    return 0;
}