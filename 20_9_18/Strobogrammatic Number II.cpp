#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> func(int n)
    {
        if (n == 1)
        {
            return vector<string>{"0", "1", "8"};
        }
        else if (n == 2)
        {
            return vector<string>{"11", "88", "69", "96"};
        }

        if (n % 2 == 0)
        {
            vector<string> v = func(n - 2);
            int len = v.size();
            for (int i = 0; i < len; i++)
            {
                int middle = (n - 2) / 2;
                v.push_back(v[i].substr(0, middle) + "00" + v[i].substr(middle));
                v.push_back(v[i].substr(0, middle) + "11" + v[i].substr(middle));
                v.push_back(v[i].substr(0, middle) + "88" + v[i].substr(middle));
                v.push_back(v[i].substr(0, middle) + "69" + v[i].substr(middle));
                v.push_back(v[i].substr(0, middle) + "96" + v[i].substr(middle));
            }

            return vector<string>(v.begin() + len, v.end());
        }
        else
        {
            vector<string> v = func(n - 1);
            int len = v.size();
            for (int i = 0; i < len; i++)
            {
                v.push_back(v[i].substr(0, n / 2) + "0" + v[i].substr(n / 2));
                v.push_back(v[i].substr(0, n / 2) + "1" + v[i].substr(n / 2));
                v.push_back(v[i].substr(0, n / 2) + "8" + v[i].substr(n / 2));
            }

            return vector<string>(v.begin() + len, v.end());
        }
    }

    vector<string> findStrobogrammatic(int n)
    {
        return func(n);
    }
};