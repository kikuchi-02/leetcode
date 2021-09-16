

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(vector<int> root, int x)
    {
        if (x == root[x])
        {
            return x;
        }
        return find(root, root[x]);
    }
    void unionset(vector<int> &root, int x, int y)
    {
        int rootX = find(root, x);
        int rootY = find(root, y);
        if (rootX != rootY)
        {
            root[rootY] = rootX;
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        vector<int> v = {};
        for (int i = 0; i < isConnected.size(); i++)
        {
            v.push_back(i);
        }

        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = 0; j < isConnected.size(); j++)
            {
                if (i != j && isConnected[i][j] == 1)
                {
                    unionset(v, i, j);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (i == v[i])
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    vector<vector<int>> v = {{1, 1, 0},
                             {1, 1, 0},
                             {0, 0, 1}};
    int res = Solution()
                  .findCircleNum(v);
    cout << res << endl;

    return 1;
}