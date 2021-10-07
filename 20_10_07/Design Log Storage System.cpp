#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

class LogSystem {
   public:
    map<string, vector<int>> hashmap;
    LogSystem() {
    }

    void put(int id, string timestamp) {
        hashmap[timestamp].push_back(id);
    }

    vector<int> retrieve(string start, string end, string granularity) {
        int sz;
        if (granularity == "Year") {
            sz = 4;
        } else if (granularity == "Month") {
            sz = 4 + 1 + 2;
        } else if (granularity == "Day") {
            sz = 4 + 1 + 2 + 1 + 2;
        } else if (granularity == "Hour") {
            sz = 4 + 1 + 2 + 1 + 2 + 1 + 2;
        } else if (granularity == "Minute") {
            sz = 4 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2;
        } else {
            sz = 4 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2;
        }
        string suffix = "9999:99:99:99:99:99";

        string startSub = start.substr(0, sz);
        string endSub = end.substr(0, sz) + suffix.substr(sz);

        vector<int> result;

        auto lo = hashmap.lower_bound(startSub);
        auto up = hashmap.upper_bound(endSub);
        while (lo != up) {
            for (int i : lo->second) {
                result.push_back(i);
            }
            lo++;
        }

        return result;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */