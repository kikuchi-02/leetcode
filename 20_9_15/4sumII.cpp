#include <bits/stdc++.h>
using namespace std;

#include <unordered_map>

class Solution
{
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
  {
    unordered_map<int, int> hashmap0;
    unordered_map<int, int> hashmap1;
    unordered_map<int, int> hashmap2;
    unordered_map<int, int> hashmap3;

    int length = nums1.size();
    for (int i = 0; i < length; i++)
    {
      int v0 = nums1[i];
      if (hashmap0.count(v0) == 0)
      {
        hashmap0[v0] = 1;
      }
      else
      {
        hashmap0[v0] += 1;
      }
      int v1 = nums2[i];
      if (hashmap1.count(v1) == 0)
      {
        hashmap1[v1] = 1;
      }
      else
      {
        hashmap1[v1] += 1;
      }
      int v2 = nums3[i];
      if (hashmap2.count(v2) == 0)
      {
        hashmap2[v2] = 1;
      }
      else
      {
        hashmap2[v2] += 1;
      }
      int v3 = nums4[i];
      if (hashmap3.count(v3) == 0)
      {
        hashmap3[v3] = 1;
      }
      else
      {
        hashmap3[v3] += 1;
      }
    }

    int counter = 0;

    for (auto it0 = hashmap0.begin(); it0 != hashmap0.end(); ++it0)
    {
      for (auto it1 = hashmap1.begin(); it1 != hashmap1.end(); ++it1)
      {
        for (auto it2 = hashmap2.begin(); it2 != hashmap2.end(); ++it2)
        {
          int sum = it0->first + it1->first + it2->first;
          if (hashmap3.count(-sum) > 0)
          {
            int last = hashmap3.count(-sum);
            counter += it0->second * it1->second * it2->second * last;
          }
        }
      }
    }
    return counter;
  }
};
