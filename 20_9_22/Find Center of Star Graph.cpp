#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        vector<int> v = {edges[0][0],
                         edges[0][1]};
        for (int i = 0; i < edges.size(); i++)
        {
            if (v.size() == 1)
            {
                return v[0];
            }
            for (int j = 0; j < v.size(); j++)
            {
                if (v[j] == edges[i][0] || v[j] == edges[i][1])
                {
                    continue;
                }
                else
                {
                    v.erase(v.begin() + j);
                }
            }
        }
        return v[0];
    }
};