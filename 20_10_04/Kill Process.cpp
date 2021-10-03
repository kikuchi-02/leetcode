#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int> > hashmap;

        for (int i = 0; i < ppid.size(); i++) {
            if (ppid[i] != 0) {
                hashmap[ppid[i]].push_back(pid[i]);
            }
        }

        vector<int> target;
        target.push_back(kill);
        int i = 0;
        while (i < target.size()) {
            if (hashmap.find(target[i]) != hashmap.end()) {
                for (int v : hashmap[target[i]]) {
                    target.push_back(v);
                }
            }
            i++;
        }
        return target;
    }
};