// https://leetcode.com/problems/minimize-the-total-price-of-the-trips/
#include "xxx.hpp"

class Solution {
public:
  int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price,
                        vector<vector<int>> &trips) {
    neibs_ = vector<vector<int>>(n);
    for (auto &e : edges) {
      neibs_[e[0]].push_back(e[1]);
      neibs_[e[1]].push_back(e[0]);
    }
    dp_ = vector<vector<int>>(51, vector<int>(2, -1));
    // calculate the node in trips
    node_acc_ = vector<int>(n, 0);

    for (auto &trip : trips) {
      vector<int> path;
      visit(trip[0], -1, trip[1], path);
    }

    return dfs(0, -1, false, price);
  }

private:
  int dfs(int start, int parent, bool parent_halved, vector<int> &price) {
    // current node halved
    int ret1 = (node_acc_[start] * price[start]) / 2;
    // current not cut
    int ret2 = node_acc_[start] * price[start];
    if (dp_[start][parent_halved] != -1) {
      return dp_[start][parent_halved];
    }
    for (auto &next : neibs_[start]) {
      if (next != parent) {
        // follow the cur not cut, for child, cur is parent so
        // parent_halved is false
        ret2 += dfs(next, start, false, price);
      }
    }
    if (parent_halved) {
      // can not half current node, so we take ret2
      return dp_[start][parent_halved] = ret2;
    }
    for (auto &next : neibs_[start]) {
      if (next != parent) {
        ret1 += dfs(next, start, true, price);
      }
    }
    // we can take the lower case
    return dp_[start][parent_halved] = min(ret1, ret2);
  }

  void visit(int cur, int parent, int target, vector<int> &path) {
    path.push_back(cur);
    if (cur == target) {
      for (auto &node : path) {
        node_acc_[node]++;
      }
      path.pop_back();
      return;
    }
    for (auto &next : neibs_[cur]) {
      if (next != parent) {
        visit(next, cur, target, path);
      }
    }

    path.pop_back();
  }

private:
  vector<vector<int>> neibs_;
  vector<vector<int>> dp_;
  vector<int> node_acc_;
};
