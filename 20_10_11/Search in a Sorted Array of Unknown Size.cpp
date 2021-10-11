#include <bits/stdc++.h>
using namespace std;

// This is the ArrayReader's API interface.
// You should not implement it, or speculate about its implementation
class ArrayReader {
   public:
    int get(int index) {
        return 1;
    }
};

class Solution {
   public:
    int search(const ArrayReader& reader, int target) {
        int l = 0, r = 1;
        while (reader.get(r) < target) {
            l = r;
            r <<= 1;
        }
        int pivot, num;
        while (l <= r) {
            pivot = l + ((r - l) >> 1);
            num = reader.get(pivot);
            if (num == target) {
                return pivot;
            }
            if (num > target) {
                r = pivot - 1;
            } else {
                l = pivot + 1;
            }
        }
        return -1;
    }
};