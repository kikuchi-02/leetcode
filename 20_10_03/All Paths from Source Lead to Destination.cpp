#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool helper(int node, int dest, vector<int>& state, vector<vector<int>>& graph) {
        if (state[node] != 0) {
            return state[node] == 2;
        }

        if (graph[node].size() == 0) {
            return node == dest;
        }
        state[node] = 1;
        for (int& g : graph[node]) {
            if (!helper(g, dest, state, graph)) {
                return false;
            }
        }
        state[node] = 2;
        return true;
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> state(n);
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
        }
        return helper(source, destination, state, graph);
    }
};