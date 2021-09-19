
#include <bits/stdc++.h>
using namespace std;

class Codec
{
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs)
    {
        string str;
        str += to_string(strs.size()) + "_";

        string t;
        for (string s : strs)
        {
            str += to_string(s.length()) + "_";
            t += s;
        }

        str += t;

        return str;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s)
    {
        int i = 0;
        int size = stoi(string(1, s[i]));
        i += 2;
        vector<int> wordLengths;
        for (int j = 0; j < size; j++)
        {
            i += j * 2;
            wordLengths.push_back(stoi(string(1, s[i])));
        }
        i += 2;
        vector<string> result;
        for (int l : wordLengths)
        {
            result.push_back(s.substr(i, l));
            i += l;
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

// TODO bytesの扱い