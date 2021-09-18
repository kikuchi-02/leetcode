#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper)
    {
        vector<string> result;
        int start = lower;
        for (auto n : nums)
        {
            if (n == start + 1)
            {
                string s = to_string(start);
                result.push_back(s);
            }
            else if (n > start + 1)
            {
                string s = to_string(start) + "->" + to_string(n - 1);
                result.push_back(s);
            }
            start = n + 1;
        }

        if (upper == start)
        {
            string s = to_string(start);
            result.push_back(s);
        }
        else if (upper > start)
        {
            string s = to_string(start) + "->" + to_string(upper);
            result.push_back(s);
        }
        return result;
    }
};