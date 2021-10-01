#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string helper(int& i, string expression) {
        if (i + 1 == expression.size() || expression.at(i + 1) != '?') {
            return expression.substr(i, 1);
        }

        char v = expression.at(i);
        i += 2;
        string thenV = helper(i, expression);
        i += 2;
        string elseV = helper(i, expression);

        if (v == 'T') {
            return thenV;
        } else {
            return elseV;
        }
    }
    string parseTernary(string expression) {
        int i = 0;
        return helper(i, expression);
    }
};