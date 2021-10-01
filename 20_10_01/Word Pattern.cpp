#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>
#include <unordered_set>

class Solution {
   public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> hashmap;
        unordered_set<char> hashset;

        int p = 0;

        int i = 0;
        while (i < s.length()) {
            if (p >= pattern.size()) {
                return false;
            }

            int j = i;
            while (j < s.length() && s.at(j) != ' ') {
                j++;
            }
            string sub = s.substr(i, j - i);

            if (hashmap.find(sub) != hashmap.end()) {
                char c = hashmap[sub];
                if (c != pattern.at(p)) {
                    return false;
                }
            } else {
                if (hashset.find(pattern.at(p)) != hashset.end()) {
                    return false;
                }
                hashmap[sub] = pattern.at(p);
                hashset.insert(pattern.at(p));
            }
            p++;
            i = j + 1;
        }
        return p >= pattern.size();
    }
};