#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class TwoSum
{
public:
    unordered_map<int, int> hashmap;
    int uplim;
    int lowlim;
    /** Initialize your data structure here. */
    TwoSum()
    {
        uplim = pow(10, 5) * 2;
        lowlim = -pow(10, 5) * 2;
    }

    /** Add the number to an internal data structure.. */
    void add(int number)
    {
        ++hashmap[number];
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value)
    {
        if (value > uplim || value < lowlim)
        {
            return false;
        }

        for (auto it = hashmap.begin(); it != hashmap.end(); ++it)
        {
            if (it->first == value - it->first)
            {

                if (it->second > 1)
                {
                    return true;
                }
            }
            else if (hashmap.count(value - it->first) > 0)
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */