#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> arr(length);

        for (int i = 0; i < updates.size(); i++) {
            if (updates[i][1] + 1 < length) {
                arr[updates[i][1] + 1] -= updates[i][2];
            }
            arr[updates[i][0]] += updates[i][2];
        }

        for (int i = 1; i < arr.size(); i++) {
            arr[i] += arr[i - 1];
        }
        return arr;
    }
};
