#include <bits/stdc++.h>
using namespace std;

class MaxStack {
   public:
    vector<int> v;
    /** initialize your data structure here. */
    MaxStack() {
        v = {};
    }

    void push(int x) {
        v.push_back(x);
    }

    int pop() {
        int a = top();
        v.pop_back();
        return a;
    }

    int top() {
        return v[v.size() - 1];
    }

    int peekMax() {
        int maxNum = v[0];
        for (int i = 1; i < v.size(); i++) {
            maxNum = max(maxNum, v[i]);
        }
        return maxNum;
    }

    int popMax() {
        int maxNum = v[0];
        int index = 0;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] >= maxNum) {
                maxNum = v[i];
                index = i;
            }
        }
        v.erase(v.begin() + index);
        return maxNum;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
