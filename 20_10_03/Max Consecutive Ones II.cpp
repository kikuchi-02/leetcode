#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxNum = 0;

        int preCount = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                maxNum = max(maxNum, count + preCount);
                preCount = count + 1;
                count = 0;
            }

            if (i == nums.size() - 1) {
                maxNum = max(maxNum, count + preCount);
            }
        }
        return maxNum;
    }
};