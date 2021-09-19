
#include <bits/stdc++.h>
using namespace std;

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution
{
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n)
    {
        int amari = n % 4;
        int shou = (n - amari) / 4;
        for (int i = 0; i < shou; i++)
        {
            int res = read4(&buf);
            if (i == shou - 1)
            {
                return n - (4 - res);
            }
        }
    }
};