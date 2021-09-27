#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

class Solution {
   public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums2.size(); i++) {
            hashmap[nums2[i]] = i;
        }

        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = hashmap[nums1[i]];
        }
        return nums1;
    }
};