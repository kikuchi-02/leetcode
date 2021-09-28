#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int largestUniqueNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int i = 0;
        while (i < nums.size()) {
            int j = i + 1;
            while (j < nums.size() && nums[i] == nums[j]) {
                j++;
            }
            if (j - i == 1) {
                return nums[i];
            } else {
                i = j;
            }
        }
        return -1;
    }
};