#include <bits/stdc++.h>
using namespace std;

class StringIterator {
   public:
    string s;
    int ptr = 0, num = 0;
    char ch = ' ';
    StringIterator(string compressedString) {
        s = compressedString;
    }

    char next() {
        if (!hasNext()) {
            return ' ';
        }
        if (num == 0) {
            ch = s.at(ptr++);
            while (ptr < s.size() && isdigit(s.at(ptr))) {
                num = num * 10 + s.at(ptr++) - '0';
            }
        }
        num--;
        return ch;
    }

    bool hasNext() {
        return ptr < s.size() || num > 0;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */