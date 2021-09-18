#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string getAscii(string s)
    {
        string key = "0";
        int last = int(s[0]);
        for (int i = 1; i < s.length(); i++)
        {
            int current = int(s[i]);
            int diff = current - last;
            if (diff < 0)
            {
                diff += int('z') - int('a') + 1;
            }

            key += "," + to_string(diff);
            last = current;
        }
        return key;
    }

    vector<vector<string>> groupStrings(vector<string> &strings)
    {
        unordered_map<string, vector<string>> hashmap;
        for (auto &s : strings)
        {
            hashmap[getAscii(s)].push_back(s);
        }

        vector<vector<string>> v;
        for (auto &s : hashmap)
        {
            v.push_back(s.second);
        }
        return v;
    }
};