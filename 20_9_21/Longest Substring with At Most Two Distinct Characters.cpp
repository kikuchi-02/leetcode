
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        int i = 0, j = 0, k = 0;
        int maxLength = 0;
        while (k < s.length())
        {
            if (s[k] != s[i])
            {
                if (i == j)
                {
                    j = k;
                }
                else if (s[k] != s[j])
                {
                    maxLength = max(maxLength, k - i);
                    i = j;
                    k = j;
                }
            }
            if (k == s.length() - 1)
            {
                maxLength = max(maxLength, k - i + 1);
            }

            k++;
        }
        return maxLength;
    }
};