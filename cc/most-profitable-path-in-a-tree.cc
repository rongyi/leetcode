// https://leetcode.com/problems/most-profitable-path-in-a-tree/
#include "xxx.hpp"

class Solution {
public:
  int mostProfitablePath(vector<vector<int>> &edges, int bob,
                         vector<int> &amount) {
    int sz = amount.size();
    dist_.resize(sz);
    parent_.resize(sz);
    neibs_.resize(sz);

    for (auto &e : edges) {
      neibs_[e[0]].push_back(e[1]);
      neibs_[e[1]].push_back(e[0]);
    }

    dfs(0, -1, 0);

    int cur = bob;
    int bob_distance = 0;

    while (parent_[cur] != -1) {
      if (dist_[cur] > bob_distance) {
        amount[cur] = 0;
      } else if (dist_[cur] == bob_distance) {
        amount[cur] /= 2;
      }

      cur = parent_[cur];
      bob_distance += 1;
    }

    return max_sum(0, amount, -1);
  }

private:
  int max_sum(int cur, vector<int> &amount, int parent) {
    int ret = amount[cur];
    int sub_sum = numeric_limits<int>::min();
    for (auto &next : neibs_[cur]) {
      if (next == parent) {
        continue;
      }
      sub_sum = max(sub_sum, max_sum(next, amount, cur));
    }
    if (sub_sum != numeric_limits<int>::min()) {
      ret += sub_sum;
    }

    return ret;
  }
  // distance: 0 -> cur
  void dfs(int cur, int parent, int distance) {
    parent_[cur] = parent;
    dist_[cur] = distance;
    for (auto &next : neibs_[cur]) {
      if (next == parent) {
        continue;
      }
      dfs(next, cur, distance + 1);
    }
  }

private:
  // root to node's distance
  vector<int> dist_;
  // node's parent, 0 -> -1
  vector<int> parent_;

  vector<vector<int>> neibs_;
};
