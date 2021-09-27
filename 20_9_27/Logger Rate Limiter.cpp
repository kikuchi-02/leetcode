#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

class Logger {
   public:
    unordered_map<string, int> hashmap;
    Logger() {
        hashmap.clear();
    }

    bool shouldPrintMessage(int timestamp, string message) {
        if (hashmap.find(message) != hashmap.end()) {
            int oldTimestamp = hashmap[message];
            if (timestamp < oldTimestamp) {
                return false;
            }
        }
        hashmap[message] = timestamp + 10;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */