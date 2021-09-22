
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int numWays(int n, int k)
    {
        if (n == 1)
        {
            return k;
        }

        int v1 = k;
        int v2 = k * k;
        for (int i = 2; i < n; i++)
        {
            int result = v2 * (k - 1) + v1 * (k - 1);
            v1 = v2;
            v2 = result;
        }
        return v2;
    }
};