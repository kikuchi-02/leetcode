#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r && !(nums[l] == target && nums[r] == target)) {
            if (nums[l] < target) {
                l++;
            }
            if (nums[r] > target) {
                r--;
            }
        }
        return (nums[l] == target && nums[r] == target) && (r - l + 1 > nums.size() / 2);
    }
};