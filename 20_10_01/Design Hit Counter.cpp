#include <bits/stdc++.h>
using namespace std;

class HitCounter {
   public:
    vector<pair<int, int>> v;
    HitCounter() {
    }

    void hit(int timestamp) {
        if (v.size() == 0) {
            v.push_back(make_pair(timestamp, 1));
            return;
        }
        auto last = v[v.size() - 1];
        if (last.first == timestamp) {
            last.second += 1;
            v[v.size() - 1] = last;
            return;
        }
        v.push_back(make_pair(timestamp, last.second + 1));
    }

    int getHits(int timestamp) {
        int j = v.size() - 1;
        int c = 0;
        while (0 <= j) {
            if (c == 0 && v[j].first <= timestamp) {
                c = v[j].second;
            }

            if (v[j].first <= timestamp - 300) {
                c -= v[j].second;
                break;
            }
            j--;
        }

        return c;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */