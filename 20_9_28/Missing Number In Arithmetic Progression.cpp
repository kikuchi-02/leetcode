#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int missingNumber(vector<int>& arr) {
        int diff = (arr[arr.size() - 1] - arr[0]) / (int)arr.size();

        int l = 0, r = arr.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (arr[mid] == arr[0] + mid * diff) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return arr[0] + diff * l;
    }
};