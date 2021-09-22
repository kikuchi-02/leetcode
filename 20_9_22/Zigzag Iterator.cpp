#include <bits/stdc++.h>
using namespace std;

class ZigzagIterator
{
public:
    vector<int> a;
    vector<int> b;
    int i = 0;
    int j = 0;

    ZigzagIterator(vector<int> &v1, vector<int> &v2)
    {
        a = v1;
        b = v2;
    }

    int next()
    {
        if (i < a.size() && j < b.size())
        {
            if (i <= j)
            {
                return a[i++];
            }
            else if (j < i)
            {
                return b[j++];
            }
        }
        if (i < a.size())
        {
            return a[i++];
        }
        else
        {
            return b[j++];
        }
    }

    bool hasNext()
    {
        return i < a.size() || j < b.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */