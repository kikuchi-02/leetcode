#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isOneEditDistance(string s, string t)
    {
        if (s.length() > t.length())
        {
            return isOneEditDistance(t, s);
        }
        int i = 0;
        int j = 0;

        if (t.length() - t.length() > 1)
        {
            return false;
        }

        while (i < s.length())
        {

            if (s.at(i) != t.at(j))
            {
                if (s.length() == t.length())
                {
                    return s.substr(i + 1) == t.substr(j + 1);
                }
                else
                {
                    return s.substr(i) == t.substr(j + 1);
                }
            }

            i++;
            j++;
        }

        return s.length() + 1 == t.length();
    }
};