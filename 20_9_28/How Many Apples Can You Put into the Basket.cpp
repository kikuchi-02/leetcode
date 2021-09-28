#include <bits/stdc++.h>

#include <queue>
using namespace std;

class Solution {
   public:
    int maxNumberOfApples(vector<int>& weight) {
        priority_queue<int, vector<int>, greater<int>> que(weight.begin(), weight.end());
        int sum = 0, count = 0;
        while (!que.empty() && sum + que.top() < 5000) {
            sum += que.top();
            que.pop();
            count++;
        }
        return count;
    }
};