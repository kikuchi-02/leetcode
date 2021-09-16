#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>

// class Solution
// {
// public:
//   int lengthOfLongestSubstring(string s)
//   {
//     int max_length = 0;

//     for (int i = 0; i < s.length(); i++)
//     {
//       unordered_set<char> hashset;
//       for (int j = i; j < s.length(); j++)
//       {
//         char c = s.at(j);
//         if (hashset.count(c) > 0)
//         {
//           if (hashset.size() > max_length)
//           {
//             max_length = hashset.size();
//             hashset.clear();
//           }
//           break;
//         }
//         hashset.insert(c);
//       }
//       if (hashset.size() > max_length)
//       {
//         max_length = hashset.size();
//       }
//     }

//     return max_length;
//   }
// };

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int max_length = 0;
    int del = -1;

    unordered_map<char, int> hashmap;

    for (int i = 0; i < s.length(); i++)
    {
      char c = s.at(i);
      if (hashmap.count(c) > 0)
      {
        if (hashmap.size() > max_length)
        {
          max_length = hashmap.size();
        }
        for (int j = del; j < hashmap[c]; j++)
        {
          hashmap.erase(s.at(j + 1));
          del = j + 1;
        }
      }

      hashmap[c] = i;
    }

    if (hashmap.size() > max_length)
    {
      max_length = hashmap.size();
    }

    return max_length;
  }
};

int main()
{
  // int res = Solution().lengthOfLongestSubstring("pwwkew");
  int res = Solution().lengthOfLongestSubstring("aabaab!bb");
  // int res = Solution().lengthOfLongestSubstring("umvejcuuk");
  cout << res << endl;

  return 1;
}
