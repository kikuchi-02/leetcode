#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class WordDistance
{
public:
    unordered_map<string, vector<int>> words;
    WordDistance(vector<string> &wordsDict)
    {
        for (int i = 0; i < wordsDict.size(); ++i)
        {
            words[wordsDict[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2)
    {
        auto a = words[word1];
        auto b = words[word2];
        int i = 0;
        int j = 0;

        int minWidth = abs(a[i] - b[j]);
        while (i < a.size() && j < b.size())
        {
            minWidth = min(minWidth, abs(a[i] - b[j]));
            if (a[i] < b[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return minWidth;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */