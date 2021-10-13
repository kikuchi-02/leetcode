#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<string> expand(string s) {
        vector<string> result;
        result.push_back("");

        int i = 0;
        int baseSize = 0;

        while (i < s.length()) {
            if (baseSize > 0) {
                if (s[i + 1] == '}') {
                    for (int j = 0; j < baseSize; j++) {
                        result[j] += s[i];
                    }
                    baseSize = 0;
                } else {
                    for (int j = 0; j < baseSize; j++) {
                        result.push_back(result[j] + s[i]);
                    }
                }
                i += 2;
            } else {
                if (s[i] == '{') {
                    baseSize = result.size();
                } else {
                    for (int j = 0; j < result.size(); j++) {
                        result[j] += s[i];
                    }
                }
                i++;
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};