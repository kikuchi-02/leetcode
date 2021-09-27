#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool confusingNumber(int n) {
        int reversed = 0;
        int m = n;
        while (m > 0) {
            int v = m % 10;
            m /= 10;
            if (v == 0 || v == 1 || v == 8) {
            } else if (v == 6) {
                v = 9;
            } else if (v == 9) {
                v = 6;
            } else {
                return false;
            }
            reversed = reversed * 10 + v;
        }
        return reversed != n;
    }
};