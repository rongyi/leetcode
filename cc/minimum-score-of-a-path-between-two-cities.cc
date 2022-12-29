// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
#include "xxx.hpp"

class Solution {
public:
  int minScore(int n, vector<vector<int>> &roads) {
    vector<vector<pair<int, int>>> neibs(n + 1);
    for (auto &r : roads) {
      neibs[r[0]].push_back({r[1], r[2]});
      neibs[r[1]].push_back({r[0], r[2]});
    }

    int minpath = numeric_limits<int>::max();
    set<int> visited;
    return dfs(1, neibs, visited);
  }

private:
  int dfs(int cur, vector<vector<pair<int, int>>> &neibs, set<int> &visited) {
    int ret = numeric_limits<int>::max();
    visited.insert(cur);
    for (auto &next : neibs[cur]) {
      if (!visited.count(next.first)) {
        ret = min(ret, dfs(next.first, neibs, visited));
      }
      ret = min(ret, next.second);
    }

    return ret;
  }
};
