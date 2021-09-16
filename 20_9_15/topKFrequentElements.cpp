#include <bits/stdc++.h>
using namespace std;

#include <unordered_map>
#include <unordered_set>

class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    unordered_map<int, int> hashmap;

    for (int i = 0; i < nums.size(); i++)
    {
      int n = nums[i];
      if (hashmap.count(n) > 0)
      {
        hashmap[n] += 1;
      }
      else
      {
        hashmap[n] = 1;
      }
    }

    vector<int> result;
    while (result.size() < k)
    {
      int max = 0;
      int key = 0;
      for (auto it = hashmap.begin(); it != hashmap.end(); it++)
      {
        if (it->second > max)
        {
          max = it->second;
          key = it->first;
        }
      }
      result.push_back(key);
      hashmap.erase(key);
    }
    return result;
  }
};
