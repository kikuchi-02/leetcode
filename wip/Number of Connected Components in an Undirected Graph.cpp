
#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    vector<int> root;
    vector<int> rank;
    int count;

    UnionFind(int sz) : root(sz), rank(sz), count(sz)
    {
        for (int i = 0; i < sz; i++)
        {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x)
    {
        if (root[x] == x)
        {
            return x;
        }
        return find(root[x]);
    }

    void unionSet(int x, int y)
    {
        int rootX = root[x];
        int rootY = root[y];
        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
            {
                root[rootY] = rootX;
            }
            else if (rank[rootY] < rank[rootX])
            {
                root[rootX] = rootY;
            }
            else
            {
                root[rootX] = rootY;
                rank[rootY] += 1;
            }

            count--;
        }
    }

    int getCount()
    {
        return count;
    }
};

class Solution
{
public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        UnionFind uf(n);
        for (int i = 0; i < edges.size(); i++)
        {
            uf.unionSet(edges[i][0], edges[i][1]);
        }

        return uf.getCount();
    }
};

int main()
{
    int n = 5;
    vector<vector<int>> v = {
        {0, 1},
        {0, 2},
        {0, 3},
        {1, 4},
    };

    Solution()
        .countComponents(n, v);
}