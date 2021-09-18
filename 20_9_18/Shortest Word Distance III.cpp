#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestWordDistance(vector<string> &wordsDict, string word1, string word2)
    {
        int a = -1;
        int b = -1;
        int minWidth = wordsDict.size();

        for (int i = 0; i < wordsDict.size(); i++)
        {
            if (word1 == word2)
            {
                if (wordsDict[i] == word1)
                {
                    if (a != -1)
                    {
                        minWidth = min(minWidth, i - a);
                    }
                    a = i;
                }
            }
            else
            {
                if (wordsDict[i] == word1)
                {
                    a = i;
                    if (b != -1)
                    {
                        minWidth = min(minWidth, abs(a - b));
                    }
                }
                else if (wordsDict[i] == word2)
                {
                    b = i;
                    if (a != -1)
                    {
                        minWidth = min(minWidth, abs(a - b));
                    }
                }
            }
        }
        return minWidth;
    }
};