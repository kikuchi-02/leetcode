#include <bits/stdc++.h>

#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    unordered_map<char, string> hashmap;
    unordered_map<string, char> hashmap2;

    bool helper(int i, int j, string pattern, string s) {
        if (i == pattern.size()) {
            return j == s.size();
        }

        if (hashmap.find(pattern[i]) != hashmap.end()) {
            string sub = hashmap[pattern[i]];
            if (sub == s.substr(j, sub.size())) {
                return helper(i + 1, j + sub.size(), pattern, s);
            } else {
                return false;
            }
        }
        for (int k = j; k < s.size(); k++) {
            string sub = s.substr(j, k - j + 1);
            if (hashmap2.find(sub) != hashmap2.end()) {
                continue;
            }
            hashmap[pattern[i]] = sub;
            hashmap2[sub] = pattern[i];
            if (helper(i + 1, k + 1, pattern, s)) {
                return true;
            }
            hashmap.erase(pattern[i]);
            hashmap2.erase(sub);
        }
        return false;
    }
    bool wordPatternMatch(string pattern, string s) {
        return helper(0, 0, pattern, s);
    }
};