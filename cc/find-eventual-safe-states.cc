// https://leetcode.com/problems/find-eventual-safe-states/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    vector<int> ret;
    const int n = graph.size();
    vector<int> color(n);

    for (int i = 0; i < n; ++i) {
      if (nonstop(graph, i, color)) {
        ret.push_back(i);
      }
    }
    return ret;
  }
private:
  bool nonstop(vector<vector<int>> &graph, int i, vector<int> &color) {
    if (color[i] > 1) {
      return color[i] == 2;
    }
    // mark doing
    color[i] = 1;
    for (auto i : graph[i]) {
      if (color[i] == 2) {
        continue;
      }
      if (color[i] == 1 || !nonstop(graph, i, color)) {
        return false;
      }
    }
    color[i] = 2;
    return true;
  }
};
