#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int countElements(vector<int>& arr) {
        int ans = 0;
        sort(arr.begin(), arr.end());

        int i = 1;
        int count = 1;
        int last = arr[0];
        while (i < arr.size()) {
            if (arr[i] == last) {
                count++;
            } else if (arr[i] == last + 1) {
                ans += count;
                last = arr[i];
                count = 1;
            } else {
                last = arr[i];
                count = 1;
            }
            i++;
        }
        // ans += count;
        return ans;
    }
};