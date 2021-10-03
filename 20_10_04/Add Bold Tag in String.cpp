#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string addBoldTag(string s, vector<string>& words) {
        vector<bool> mask(s.size(), false);

        for (string word : words) {
            auto f = s.find(word);
            while (f != string::npos) {
                for (int i = f; i < f + word.size() && i < mask.size(); i++) {
                    mask[i] = true;
                }
                f = s.find(word, f + 1);
            }
        }
        string open = "<b>";
        string close = "</b>";

        string ans;
        for (int i = 0; i < mask.size(); i++) {
            if (mask[i] && i == 0) {
                ans += open;
                ans += s.at(i);
            } else if (mask[i] && !mask[i - 1]) {
                ans += open;
                ans += s.at(i);
            } else if (mask[i] && i == mask.size() - 1) {
                ans += s.at(i);
                ans += close;
            } else if (!mask[i] && i != 0 && mask[i - 1]) {
                ans += close;
                ans += s.at(i);
            } else {
                ans += s.at(i);
            }
        }
        return ans;
    }
};