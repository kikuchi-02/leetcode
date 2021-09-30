#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

class Solution {
   public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int length = 0;

        unordered_map<int, int> hashmap;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (sum == k) {
                length = max(length, i + 1);
            } else if (hashmap.find(sum - k) != hashmap.end()) {
                length = max(length, i - hashmap[sum - k]);
            }

            if (hashmap.find(sum) == hashmap.end()) {
                hashmap[sum] = i;
            }
        }

        return length;
    }
};