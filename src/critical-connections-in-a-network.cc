// http://leetcode.com/problems/critical-connections-in-a-network/description/
#include "xxx.h"

class Solution {
public:
  // https://www.hackerearth.com/zh/practice/notes/nj/
  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>> &connections) {
    edges_.resize(n);
    visited_.resize(n, false);
    dist_.resize(n, numeric_limits<int>::max());
    low_.resize(n, numeric_limits<int>::max());

    for (int i = 0; i < connections.size(); ++i) {
      edges_[connections[i][0]].push_back(connections[i][1]);
      edges_[connections[i][1]].push_back(connections[i][0]);
    }

    for (int i = 0; i < n; ++i) {
      if (!visited_[i]) {
        dfs(i, -1);
      }
    }
    return ret_;
  }
  void dfs(int u, int parent) {
    static int tim = 1;
    dist_[u] = low_[u] = tim++;
    int child = 0;
    visited_[u] = true;
    for (auto neib : edges_[u]) {
      if (!visited_[neib]) {
        child++;
        dfs(neib, u);
        low_[u] = min(low_[u], low_[neib]);
        if (low_[neib] > dist_[u]) {
          ret_.push_back({u, neib});
        }
      } else if (neib != parent) {
        low_[u] = min(low_[u], dist_[neib]);
      }
    }
  }

private:
  vector<vector<int>> edges_;
  vector<vector<int>> ret_;
  vector<bool> visited_;
  vector<int> dist_;
  vector<int> low_;
};
