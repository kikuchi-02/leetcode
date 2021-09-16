
#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    vector<int> root;
    int count;
    UnionFind(int sz) : root(sz), count(sz)
    {
        for (int i = 0; i < sz; i++)
        {
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

    bool unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            root[rootX] = rootY;
            count--;
        }
        cout << count << endl;
        return count == 1;
    }
};

class Solution
{
public:
    int earliestAcq(vector<vector<int>> &logs, int n)
    {
        sort(
            logs.begin(), logs.end(), [](vector<int> a, vector<int> b)
            { return a[0] < b[0]; });
        UnionFind uf(n);
        for (int i = 0; i < logs.size(); i++)
        {
            bool res = uf.unionSet(logs[i][1], logs[i][2]);
            if (res)
            {
                return logs[i][0];
            }
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> v = {
        {20190101, 0, 1},
        {20190104, 3, 4},
        {20190107, 2, 3},
        {20190211, 1, 5},
        {20190224, 2, 4},
        {20190301, 0, 3},
        {20190312, 1, 2},
        {20190322, 4, 5},
    };
    int n = 6;
    int res = Solution().earliestAcq(v, n);
    cout << res << endl;
}