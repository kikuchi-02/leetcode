
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string longestPalindrome(string s)
  {
    string sub = "";
    string next_sub = "";
    for (int i = 0; i < s.length(); i++)
    {
      int left = i - 1;
      int right = i + 1;
      string n = string(1, s.at(i));
      while (0 <= left && right <= s.length() - 1 && s.at(left) == s.at(right))
      {
        n = s.at(left) + n + s.at(left);
        left -= 1;
        right += 1;
      }
      if (n.length() > sub.length())
      {
        sub = n;
      }

      int current = i;
      int next = i + 1;
      string m = "";
      while (0 <= current && next <= s.length() - 1 && s.at(current) == s.at(next))
      {
        m = s.at(current) + m + s.at(current);
        current -= 1;
        next += 1;
      }
      if (m.length() > sub.length())
      {
        sub = m;
      }
    }
    return sub;
  }
};

int main()
{
  string str = Solution().longestPalindrome("babad");
  cout << str << endl;
  return 1;
}
// https://leetcode.com/problems/longest-palindromic-substring/
