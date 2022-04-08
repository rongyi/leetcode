// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    vector<vector<int>> ret(n, vector<int>{});
    vector<vector<int>> graph(n, vector<int>{});

    for (auto &e : edges) {
      graph[e[0]].push_back(e[1]);
    }
    // start from all nodes
    for (int i = 0; i < n; ++i) {
      vector<bool> visited(n, 0);
      dfs(i, i, graph, ret);
    }

    return ret;
  }

private:
  void dfs(int cur, int parent, vector<vector<int>> &graph,
           vector<vector<int>> &ret) {
    for (auto &c : graph[cur]) {
      // incase the multiple entrance!
      // this is the most beautiful check in dfs!
      if (ret[c].empty() || ret[c].back() != parent) {
        ret[c].push_back(parent);
        dfs(c, parent, graph, ret);
      }
    }
  }
};
