

#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    vector<int> rank;
    int count;

public:
    vector<int> root;

    UnionFind(int sz) : root(sz), rank(sz), count(sz)
    {
        for (int i = 0; i < sz; i++)
        {
            rank[i] = 1;
            root[i] = i;
        }
    }

    int find(int x)
    {
        if (x == root[x])
        {
            return x;
        }
        return find(root[x]);
    }

    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
            {
                root[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY])
            {
                root[rootY] = rootX;
            }
            else
            {
                root[rootY] = rootX;
                rank[rootX] += 1;
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
    bool validTree(int n, vector<vector<int>> &edges)
    {
        UnionFind uf(n);

        for (int i = 0; i < edges.size(); i++)
        {
            uf.unionSet(edges[i][0], edges[i][1]);
        }
        int c = 0;
        for (int i = 0; i < uf.root.size(); i++)
        {
            if (uf.root[i] == i)
            {
                c++;
            }
        }

        return c == 1 && uf.getCount() == n - edges.size();
    }
};

int main()
{
    int n = 5;
    // vector<vector<int>> v = {
    //     {0, 1},
    //     {0, 2},
    //     {0, 3},
    //     {1, 4},
    // };

    vector<vector<int>> v = {
        {0, 1},
        {1, 2},
        {2, 3},
        {1, 3},
        {1, 4},
    };

    Solution()
        .validTree(n, v);
    return 1;
}