// http://leetcode.com/problems/restore-the-array-from-adjacent-pairs/description/
#include "xxx.h"

class Solution {
public:
  vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
    map<int, set<int>> pair;
    for (auto &p : adjacentPairs) {
      pair[p[0]].insert(p[1]);
      pair[p[1]].insert(p[0]);
    }

    int edge = -1;
    for (auto &kv : pair) {
      if (kv.second.size() == 1) {
        // found the edge
        edge = kv.first;
        break;
      }
    }

    vector<int> ret;
    set<int> visited;
    dfs(edge, pair, visited, ret);

    return ret;
  }

private:
  void dfs(int cur, map<int, set<int>> &pair, set<int> &visited,
           vector<int> &ret) {
    if (visited.find(cur) != visited.end()) {
      return;
    }
    if (ret.size() >= pair.size()) {
      return;
    }
    visited.insert(cur);
    ret.push_back(cur);
    for (auto n: pair[cur]) {
      dfs(n, pair, visited, ret);
    }
  }
};
