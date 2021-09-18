#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestDistance(vector<string> &wordsDict, string word1, string word2)
    {
        int minWidth = wordsDict.size();
        int a = -1;
        int b = -1;
        for (int i = 0; i < wordsDict.size(); i++)
        {
            if (wordsDict[i] == word1)
            {
                a = i;
                if (b != -1)
                {
                    minWidth = min(a - b, minWidth);
                }
            }
            else if (wordsDict[i] == word2)
            {
                b = i;
                if (a != -1)
                {
                    minWidth = min(b - a, minWidth);
                }
            }
        }
        return minWidth;
    }
};