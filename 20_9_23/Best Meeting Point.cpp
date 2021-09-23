#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTotalDistance(vector<vector<int>> &grid)
    {
        vector<int> rows;
        vector<int> columns;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    rows.push_back(i);
                }
            }
        }
        for (int i = 0; i < grid[0].size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                if (grid[j][i])
                {
                    columns.push_back(i);
                }
            }
        }
        return minDis(rows) + minDis(columns);
    }

    int minDis(vector<int> &vectors)
    {
        int dis = 0;
        int i = 0;
        int j = vectors.size() - 1;

        while (i < j)
        {
            dis += vectors[j] - vectors[i];
            i++;
            j--;
        }
        return dis;
    }
};