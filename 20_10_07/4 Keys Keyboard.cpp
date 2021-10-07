#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxA(int n) {
        vector<int> dp(n + 1);

        for (int i = 0; i < n + 1; i++) {
            dp[i] = i;
            for (int j = 1; j <= i - 3; j++) {
                dp[i] = max(dp[i], dp[j] * (i - j - 1));
            }
        }
        return dp[n];
    }
};