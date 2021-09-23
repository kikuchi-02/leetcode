#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minArea(vector<vector<char>> &image, int x, int y) {
        int left = 0;
        int right = image[0].size() - 1;
        int top = 0;
        int bottom = image.size() - 1;

        bool found = false;
        while (!found) {
            for (int i = left; i <= right; i++) {
                if (image[top][i] == '1') {
                    found = true;
                    break;
                }
            }
            if (!found) {
                top++;
            }
        }

        found = false;
        while (!found) {
            for (int i = left; i <= right; i++) {
                if (image[bottom][i] == '1') {
                    found = true;
                    break;
                }
            }
            if (!found) {
                bottom--;
            }
        }

        found = false;
        while (!found) {
            for (int i = top; i <= bottom; i++) {
                if (image[i][left] == '1') {
                    found = true;
                    break;
                }
            }
            if (!found) {
                left++;
            }
        }

        found = false;
        while (!found) {
            for (int i = top; i <= bottom; i++) {
                if (image[i][right] == '1') {
                    found = true;
                    break;
                }
            }
            if (!found) {
                right--;
            }
        }
        return (right - left + 1) * (bottom - top + 1);
    }
};