
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int threeSumSmaller(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            sum += towSumSmaller(nums, i + 1, target - nums[i]);
        }
        return sum;
    }
    int towSumSmaller(vector<int> &nums, int startIndex, int target)
    {
        int sum = 0;
        int left = startIndex;
        int right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] < target)
            {
                sum += right - left;
                left++;
            }
            else
            {
                right--;
            }
        }
        return sum;
    }
};