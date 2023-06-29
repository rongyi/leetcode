// https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/
#include "xxx.hpp"

class Solution {
public:
  int minIncrements(int n, vector<int> &cost) {
    dfs(1, cost, n);
    return ret_;
  }

private:
  int dfs(int idx, vector<int> &cost, int n) {
    if (idx > n) {
      return 0;
    }
    int l = dfs(idx * 2, cost, n);
    int r = dfs(idx * 2 + 1, cost, n);
    ret_ += abs(l - r);

    return cost[idx - 1] + max(l, r);
  }

private:
  int ret_ = 0;
};
