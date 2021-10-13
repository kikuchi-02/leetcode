#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

class Solution {
   public:
    int shortestWay(string source, string target) {
        int i = 0;
        int count = 0;
        while (i < target.length()) {
            bool found = false;
            int j = 0;
            while (j < source.length()) {
                if (target[i] == source[j]) {
                    i++;
                    found = true;
                }
                j++;
            }
            if (!found) {
                return -1;
            }
            count++;
        }
        return count;
    }
};