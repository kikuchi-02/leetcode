#include <bits/stdc++.h>

#include <queue>
using namespace std;

class MovingAverage {
   public:
    int count = 0, head = 0;
    int winSize;
    double sum = 0;
    vector<int> que;

    MovingAverage(int size) {
        winSize = size;
        que.resize(size);
    }

    double next(int val) {
        count++;
        int tail = (head + 1) % winSize;
        sum = sum - que[tail] + val;
        head = (head + 1) % winSize;
        que[head] = val;
        return sum / min(count, winSize);
    }
};
