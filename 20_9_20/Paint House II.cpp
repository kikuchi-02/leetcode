
#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution
{
public:
    int minCostII(vector<vector<int>> &costs)
    {
        int min1 = -1;
        int min2 = -1;
        for (int j = 0; j < costs[0].size(); j++)
        {
            if (min1 == -1 || costs[0][min1] > costs[0][j])
            {
                min2 = min1;
                min1 = j;
            }
            else if (min2 == -1 || costs[0][min2] > costs[0][j])
            {
                min2 = j;
            }
        }

        for (int i = 1; i < costs.size(); i++)
        {
            int _min1 = -1;
            int _min2 = -1;

            for (int j = 0; j < costs[i].size(); j++)
            {
                if (j == min1)
                {
                    costs[i][j] += costs[i - 1][min2];
                }
                else
                {
                    costs[i][j] += costs[i - 1][min1];
                }

                if (_min1 == -1 || costs[i][_min1] > costs[i][j])
                {
                    _min2 = _min1;
                    _min1 = j;
                }
                else if (_min2 == -1 || costs[i][_min2] > costs[i][j])
                {
                    _min2 = j;
                }
            }
            min1 = _min1;
            min2 = _min2;
        }

        return costs[costs.size() - 1][min1];
    }
};