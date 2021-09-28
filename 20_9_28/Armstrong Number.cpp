#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isArmstrong(int n) {
        int sum = 0;
        int size = log10(n) + 1;
        int m = n;
        while (m > 0) {
            int a = m % 10;
            sum += pow(a, size);
            m /= 10;
        }
        return sum == n;
    }
};