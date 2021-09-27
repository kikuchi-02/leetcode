#include <bits/stdc++.h>

#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }

        unordered_map<string, unordered_set<string>> hashmap;
        for (auto& pair : similarPairs) {
            hashmap[pair[0]].insert(pair[1]);
        }

        for (int i = 0; i < sentence1.size(); i++) {
            string s1 = sentence1[i];
            string s2 = sentence2[i];

            if (s1 == s2) {
                continue;
            }
            if (hashmap.find(s1) != hashmap.end() && hashmap[s1].find(s2) != hashmap[s1].end()) {
                continue;
            }
            if (hashmap.find(s2) != hashmap.end() && hashmap[s2].find(s1) != hashmap[s2].end()) {
                continue;
            }
            return false;
        }
        return true;
    }
};