
#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> que;

        for (auto &i : intervals)
        {
            if (que.size() > 0 && i[0] >= que.top())
            {
                que.pop();
            }
            que.push(i[1]);
        }
        return que.size();
    }
};