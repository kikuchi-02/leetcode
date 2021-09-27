#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        for (int i = 0; i < (1 << word.length()); ++i) {
            result.push_back(helper(word, i));
        }
        return result;
    }

    string helper(string word, int n) {
        string res = "";
        int k = 0;
        for (int i = 0; i < word.length(); ++i, n >>= 1) {
            if ((n & 1) == 0) {
                if (k != 0) {
                    res += to_string(k);
                    k = 0;
                }
                res += word[i];
            } else {
                ++k;
            }
        }
        if (k != 0) {
            res += to_string(k);
        }
        return res;
    }
};