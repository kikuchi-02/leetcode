
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        int v1 = nums[0];
        int v2 = nums[0];

        int maxNum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            int current = nums[i];
            int _v1 = current * v1;
            int _v2 = current * v2;

            v1 = max(current, max(_v1, _v2));
            v2 = min(current, min(_v1, _v2));
            maxNum = max(maxNum, v1);
        }
        return maxNum;
    }
};