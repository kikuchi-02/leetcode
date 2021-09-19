
#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        priority_queue<pair<int, int>> que;

        for (int i = 0; i < score.size(); i++)
        {
            que.push(make_pair(score[i], i));
        }

        vector<string> res(score.size());
        for (int i = 0; i < score.size(); i++)
        {
            auto v = que.top();
            que.pop();
            string s;
            if (i == 0)
            {
                s = "Gold Medal";
            }
            else if (i == 1)
            {
                s = "Silver Medal";
            }
            else if (i == 2)
            {
                s = "Bronze Medal";
            }
            else
            {
                s = to_string(i + 1);
            }
            res[v.second] = s;
        }
        return res;
    }
};