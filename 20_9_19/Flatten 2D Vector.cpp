
#include <bits/stdc++.h>
using namespace std;

class Vector2D
{
public:
    vector<vector<int>> vectors;
    int inner = 0;
    int outer = 0;

    Vector2D(vector<vector<int>> &vec)
    {
        vectors = vec;
    }

    int next()
    {
        int res = vectors[outer][inner];
        inner++;
        helper();
        return res;
    }

    bool hasNext()
    {
        return helper();
    }

    bool helper()
    {
        while (outer < vectors.size())
        {
            if (inner < vectors[outer].size())
            {
                return true;
            }
            inner = 0;
            outer++;
        }
        return false;
    }
};
