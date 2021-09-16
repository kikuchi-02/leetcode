#include <iostream>

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  string reverseOnlyLetters(string s)
  {
    vector<char> v;
    vector<int> mask;

    unordered_set<char> hashset = {
        'a',
        'b',
        'c',
        'd',
        'e',
        'f',
        'g',
        'h',
        'i',
        'j',
        'k',
        'l',
        'm',
        'o',
        'p',
        'q',
        'r',
        's',
        't',
        'u',
        'v',
        'w',
        'x',
        'y',
        'z',
    };

    for (int i = 0; i < s.length(); i++)
    {
      if (hashset.count(tolower(s.at(i))) > 0)
      {
        cout << s.at(i) << endl;
        cout << i << endl;
        v.push_back(s.at(i));
        mask.push_back(i);
      }
    }
    for (int i = 0; i < v.size(); i++)
    {
      s.at(mask.at(i)) = v[v.size() - 1 - i];
    }
    return s;
  }
};

int main()
{
  string s = "Test1ng-Leet=code-Q!";
  string res = Solution().reverseOnlyLetters(s);
  cout << res << endl;

  return 1;
}
