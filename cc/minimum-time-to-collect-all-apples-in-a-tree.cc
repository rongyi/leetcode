// http://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/
#include "xxx.h"

class Solution {
public:
  int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple) {
    unordered_map<int, vector<int>> nodes;
    for (auto &e : edges) {
      nodes[e[0]].push_back(e[1]);
      nodes[e[1]].push_back(e[0]);
    }

    return dfs(nodes, hasApple, 0, 0, -1) * 2;
  }

private:
  int dfs(unordered_map<int, vector<int>> &nodes, vector<bool> &hasApple,
          int cur, int dep, int prev) {
    int ret = 0;
    int child_sum = 0;
    for (auto &c : nodes[cur]) {
      if (c != prev) {
        child_sum = dfs(nodes, hasApple, c, dep + 1, cur);
        if (child_sum) {
          ret += child_sum - dep;
        }
      }
    }
    // distances of children + current distance from root
    if (ret || hasApple[cur]) {
      return ret + dep;
    }

    return 0;
  }
};
