// http://leetcode.com/problems/frog-position-after-t-seconds/description/
#include "xxx.hpp"

class Solution {
public:
  double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
    this->time_limit_ = t;
    this->target_ = target;
    table_ = vector<vector<int>>(n + 1, vector<int>());

    for (int i = 0; i < edges.size(); ++i) {
      table_[edges[i][0]].push_back(edges[i][1]);
      table_[edges[i][1]].push_back(edges[i][0]);
    }
    // start from node 1
    dfs(1, -1, 0, 1);

    return ret_;
  }

private:
  // acc 累积的时间
  // invert 实际上就是累积的child数量，取反则得到概率
  void dfs(int start, int parent, int acc, long long invert) {
    int child_size = 0;
    for (auto &v : table_[start]) {
      // 剔除节点往上的那个edge
      if (v != parent) {
        child_size++;
      }
    }
    if (start == target_) {
      if (acc == time_limit_ || (acc < time_limit_ && child_size == 0)) {
        ret_ = 1.0 / invert;
      } else {
        ret_ = 0;
      }
      return;
    }
    for (auto &v : table_[start]) {
      // 剔除节点往上的那个edge
      if (v != parent) {
        dfs(v, start, acc + 1, invert * child_size);
      }
    }
  }

private:
  double ret_;
  int target_;
  int time_limit_;
  vector<vector<int>> table_;
};
