#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int i = 0, j = 0, k = 0;
        vector<int> result;
        while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
            int v1 = arr1[i];
            int v2 = arr2[j];
            int v3 = arr3[k];

            if (v1 == v2 && v2 == v3) {
                i++;
                j++;
                k++;
                result.push_back(v1);
            } else if (v1 < v2) {
                i++;
            } else if (v2 < v3) {
                j++;
            } else {
                k++;
            }
        }
        return result;
    }
};