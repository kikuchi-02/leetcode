#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void helper(int i, int j, int counter, vector<vector<int>> &rooms)
    {
        if (i < 0 || i > rooms.size() - 1 || j < 0 || j > rooms[i].size() - 1)
        {
            return;
        }
        if (rooms[i][j] == -1 || rooms[i][j] == 0 || rooms[i][j] <= counter)
        {
            return;
        }

        rooms[i][j] = counter;

        counter++;
        helper(i - 1, j, counter, rooms);
        helper(i + 1, j, counter, rooms);
        helper(i, j - 1, counter, rooms);
        helper(i, j + 1, counter, rooms);
    }

    void wallsAndGates(vector<vector<int>> &rooms)
    {
        for (int i = 0; i < rooms.size(); i++)
        {
            for (int j = 0; j < rooms[i].size(); j++)
            {
                if (rooms[i][j] == 0)
                {
                    helper(i - 1, j, 1, rooms);
                    helper(i + 1, j, 1, rooms);
                    helper(i, j - 1, 1, rooms);
                    helper(i, j + 1, 1, rooms);
                }
            }
        }
    }
};