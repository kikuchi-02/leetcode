#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int helper(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }

    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> result(nums.size());
        if (a == 0) {
            if (b == 0) {
                result.assign(nums.size(), c);
            } else if (b > 0) {
                for (int i = 0; i < nums.size(); i++) {
                    result[i] = helper(nums[i], a, b, c);
                }
            } else {
                for (int i = 0; i < nums.size(); i++) {
                    result[i] = helper(nums[nums.size() - 1 - i], a, b, c);
                }
            }
            return result;
        }

        int idx = a < 0 ? 0 : nums.size() - 1;
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int l = helper(nums[i], a, b, c);
            int r = helper(nums[j], a, b, c);

            if (a > 0) {
                if (l < r) {
                    result[idx] = r;
                    j--;
                } else {
                    result[idx] = l;
                    i++;
                }
                idx--;
            } else {
                if (l < r) {
                    result[idx] = l;
                    i++;
                } else {
                    result[idx] = r;
                    j--;
                }
                idx++;
            }
        }
        return result;
    }
};