
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> result;

    vector<vector<int>> getFactors(int n)
    {
        vector<int> line;
        helper(n, 2, line);
        return result;
    }

    void helper(int n, int bottom, vector<int> line)
    {
        for (int i = bottom; i <= n / i; i++)
        {
            if (n % i == 0)
            {
                vector<int> newline = line;
                newline.push_back(i);
                helper(n / i, i, newline);
                newline.push_back(n / i);
                result.push_back(newline);
            }
        }
    }
};