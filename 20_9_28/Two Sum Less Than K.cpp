#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int maxSum = -1;
        int i = 0, j = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum >= k) {
                j--;
            } else {
                maxSum = max(maxSum, sum);
                i++;
            }
        }
        return maxSum;
    }
};