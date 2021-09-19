#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool search(char target, string p, int j)
    {
        if (j < 0)
        {
            return false;
        }
        if (target == p.at(j))
        {
            return true;
        }
        if (p.at(j) == '.')
        {
            return true;
        }

        if (p.at(j) == '*')
        {
            return search(target, p, j - 1);
        }
        return false;
    }

    bool isMatch(string s, string p)
    {
        for (int i = 0; i < s.length(); i++)
        {
            bool found = false;
            for (int j = i; j < p.length(); j++)
            {
                if (search(s.at(i), p, j))
                {
                    found = true;
                    continue;
                }
            }
            if (!found)
            {
                return false;
            }
        }
        return true;
    };
};