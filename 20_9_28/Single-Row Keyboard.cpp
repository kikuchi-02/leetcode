#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

class Solution {
   public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> hashmap;
        for (int i = 0; i < keyboard.size(); i++) {
            hashmap[keyboard[i]] = i;
        }
        int sum = 0;
        int last = 0;
        for (int i = 0; i < word.size(); i++) {
            sum += abs(hashmap[word[i]] - last);
            last = hashmap[word[i]];
        }
        return sum;
    }
};
