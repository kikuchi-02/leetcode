#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool canPermutePalindrome(string s)
    {
        unordered_set<char> hashset;

        for (int i = 0; i < s.length(); i++)
        {
            if (hashset.find(s[i]) != hashset.end())
            {
                hashset.erase(s[i]);
            }
            else
            {
                hashset.insert(s[i]);
            }
        }
        return hashset.size() < 2;
    }
};