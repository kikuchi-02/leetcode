#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int missingElement(vector<int>& nums, int k) {
        int _lacks = (nums[nums.size() - 1] - nums[0]) - (nums.size() - 1 - 0);
        if (_lacks < k) {
            return nums[nums.size() - 1] + (k - _lacks);
        }

        int l = 0;
        int r = nums.size() - 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            int lacks = (nums[mid] - nums[l]) - (mid - l);
            if (lacks >= k) {
                r = mid;
            } else if (k > lacks) {
                k -= lacks;
                l = mid;
            }
        }
        return nums[l] + k;
    }
};