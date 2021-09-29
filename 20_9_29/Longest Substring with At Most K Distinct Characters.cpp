#include <bits/stdc++.h>
using namespace std;

#include <queue>
#include <unordered_map>

class Solution {
   public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) {
            return 0;
        }
        unordered_map<char, int> hashmap;
        int i = 0, j = 0;
        int length = 0;

        while (j < s.size()) {
            if (hashmap.find(s[j]) == hashmap.end()) {
                while (hashmap.size() + 1 > k) {
                    if (hashmap[s[i]] == i) {
                        hashmap.erase(s[i]);
                    }
                    i++;
                }
            }
            hashmap[s[j]] = j;
            length = max(length, j - i + 1);
            j++;
        }

        return length;
    }
};