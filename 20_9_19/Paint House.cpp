
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &costs)
    {
        for (int i = 1; i < costs.size(); i++)
        {
            costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
            costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
            costs[i][2] += min(costs[i - 1][1], costs[i - 1][0]);
        }
        int last = costs.size() - 1;
        return min(min(costs[last][0], costs[last][1]), costs[last][2]);
    }
};