
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> generatePalindromes(string s)
    {
        unordered_map<char, int> hashmap(128);
        vector<char> st(s.length() / 2);

        int count = 0;
        for (char c : s)
        {
            hashmap[c]++;
            if (hashmap[c] % 2 == 0)
            {
                count--;
            }
            else
            {
                count++;
            }
        }
        if (count > 1)
        {
            return {};
        }

        char ch = 0;
        int k = 0;
        for (int i = 0; i < hashmap.size(); i++)
        {
            if (hashmap[i] % 2 == 1)
            {
                ch = (char)i;
            }
        }
    }
};
// TODO
// 解けたけど、早い解法がよくわからない。