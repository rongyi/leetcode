// http://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/
#include "xxx.hpp"

class Solution {
public:
  int minReorder(int n, vector<vector<int>> &connections) {
    vector<vector<int>> graph(n);
    for (auto &c : connections) {
      // 如果从0开始指出来则方向为正，也是我们需要调整的
      graph[c[0]].push_back(c[1]);
      graph[c[1]].push_back(-c[0]);
    }

    vector<bool> visited(n, false);

    return dfs(graph, visited, 0);
  }

private:
  int dfs(vector<vector<int>> &graph, vector<bool> &visited, int cur) {
    auto change = 0;
    visited[cur] = true;
    for (auto to : graph[cur]) {
      if (!visited[abs(to)]) {
        change += dfs(graph, visited, abs(to)) + (to > 0);
      }
    }

    return change;
  }
};
