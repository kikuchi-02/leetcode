#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> m;
        for (auto i : nums1)
        {
            m[i]++;
        }
        int k = 0;
        for (auto i : nums2)
        {
            auto it = m.find(i);
            if (it != m.end() && --it->second >= 0)
            {
                nums1[k++] = i;
            }
        }
        return vector<int>(nums1.begin(), nums1.begin() + k);
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> res = Solution().intersect(nums1, nums2);
    cout << "res" << endl;
    for (auto &i : res)
    {
        cout << i << endl;
    }
}