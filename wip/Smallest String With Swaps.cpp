
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class UnionFind
{

public:
    vector<int> root;

    UnionFind(int sz) : root(sz)
    {
        for (int i = 0; i < sz; i++)
        {
            root[i] = i;
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
            root[rootY] = rootX;
        }
    }
};

class Solution
{
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        UnionFind uf(s.length());

        for (int i = 0; i < pairs.size(); i++)
        {
            uf.unionSet(pairs[i][0], pairs[i][1]);
        }

        unordered_map<int, vector<char>>
            hashmap;
        for (int i = 0; i < s.length(); i++)
        {
            if (hashmap.count(uf.root[i]) > 0)
            {
                hashmap[uf.root[i]].push_back(s[i]);
            }
            else
            {
                hashmap[uf.root[i]] = vector<char>{s[i]};
            }
        }

        for (auto &s : hashmap)
        {
            sort(s.second.begin(), s.second.end());
        }
    }
};

int main()
{
    vector<vector<int>> v = {{0, 3}, {1, 2}};

    Solution()
        .smallestStringWithSwaps("dcab", v);
    return 1;
}