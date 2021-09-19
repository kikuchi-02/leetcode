
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        vector<int> result(nums.size() + 1);
        result[nums.size()] = 0;
        result[nums.size() - 1] = nums[nums.size() - 1];

        for (int i = nums.size() - 2; 0 <= i; i--)
        {
            result[i] = max(result[i + 2] + nums[i], result[i + 1]);
        }
        return result[0];
    }
};