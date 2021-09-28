#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int helper(int n) {
        int c = 0;
        for (int i = 1; i <= n; i++) {
            c += n - i + 1;
        }
        return c;
    }
    int countLetters(string s) {
        int count = 0;

        int tmp = 0;
        char last;
        for (int i = 0; i < s.length(); i++) {
            if (i == 0) {
                last = s.at(i);
                tmp++;
            } else if (last == s.at(i)) {
                tmp++;
            } else {
                count += helper(tmp);
                last = s.at(i);
                tmp = 1;
            }
        }
        if (tmp > 0) {
            count += helper(tmp);
        }
        return count;
    }
};