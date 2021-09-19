
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int i = 0;

    void verify(vector<int> &preorder, int minNum, int maxNum)
    {
        if (i + 1 >= preorder.size())
        {
            return;
        }
        int current = preorder[i];

        if (minNum < preorder[i + 1] && preorder[i + 1] < maxNum && preorder[i + 1] < current)
        {
            i++;
            verify(preorder, minNum, current);
        }
        if (i + 1 >= preorder.size())
        {
            return;
        }
        if (minNum < preorder[i + 1] && preorder[i + 1] < maxNum && current < preorder[i + 1])
        {
            i++;
            verify(preorder, current, maxNum);
        }
    }

    bool verifyPreorder(vector<int> &preorder)
    {
        verify(preorder, 0, 1e4);
        return i >= preorder.size() - 1;
    }
};

// TODO 理解してない。
class Solution2
{
public:
    bool verifyPreorder(vector<int> &preorder)
    {
        stack<int> s;
        int root = 0;
        for (int i = 0; i < preorder.size(); i++)
        {
            if (s.empty() || s.top() > preorder[i])
            {
                if (preorder[i] < root)
                {
                    return false;
                }
                s.push(preorder[i]);
            }
            else
            {
                while (!s.empty() && preorder[i] > s.top())
                {
                    root = s.top();
                    s.pop();
                }
                s.push(preorder[i]);
            }
        }
    }
};