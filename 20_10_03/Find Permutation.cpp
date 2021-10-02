#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findPermutation(string s) {
        vector<int> arr(s.size() + 1);
        for (int i = 0; i < s.size() + 1; i++) {
            arr[i] = i + 1;
        }
        int i = 0;
        while (i < s.size()) {
            int j = i;
            if (s[j] == 'D') {
                while (j < s.size() && s[j] == 'D') {
                    j++;
                }
                reverse(arr.begin() + i, arr.begin() + j + 1);
                i = j + 1;
            } else {
                i++;
            }
        }
        return arr;
    }
};