#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isPalindrome(vector<vector<int>> &v, string s, int i, int j)
  {
    int cache = v[i][j];
    if (cache != -1)
    {
      return cache;
    }

    bool result = s.at(i) == s.at(j) && isPalindrome(v, s, i + 1, j - 1);
    if (result)
    {
      v[i][j] = 1;
    }
    else
    {
      v[i][j] = 0;
    }
    return result;
  }

  string longestPalindrome(string s)
  {
    int i = 0;
    int j = s.length() - 1;
    vector<vector<int>> v;
    v.assign(j, vector<int>(j, -1));

    while (i <= j)
    {
      string found = "";
      for (int k = i; k <= j; k++)
      {
        if (isPalindrome(v, s, k, j))
        {
          found = s.substr(k, j + 1);
          break;
        }
      }
      for (int k = j; k >= i; k--)
      {
        if (isPalindrome(v, s, i, k))
        {
          string str = s.substr(i, k + 1);
          if (str.length() > found.length())
          {
            found = str;
          }
        }
      }
      if (found.length() > 0)
      {
        return found;
      }
    }
  }
};