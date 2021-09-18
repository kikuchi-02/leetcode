#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseWords(vector<char> &s)
    {
        reverse(s.begin(), s.end());

        int start = 0;
        int end = 0;

        while (start < s.size())
        {
            while (end < s.size() && s[end] != ' ')
            {
                end++;
            }
            reverse(s.begin() + start, s.begin() + end);
            end++;
            start = end;
        }
    }
};