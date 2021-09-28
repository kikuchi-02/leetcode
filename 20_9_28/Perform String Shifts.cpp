#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int c = 0;
        int size = s.length();
        for (auto& v : shift) {
            if (v[0] == 0) {
                c += v[1];
            } else {
                c -= v[1];
            }
        }
        c = (c % size + size) % size;

        return s.substr(c, size - c) + s.substr(0, c);
    }
};