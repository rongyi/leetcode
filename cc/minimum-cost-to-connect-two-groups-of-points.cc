// http://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/description/
#include "xxx.h"
class Solution {
public:
  int connectTwoGroups(vector<vector<int>> &cost) {
    m_ = cost.size();
    n_ = cost[0].size();
    min_each_col_ = vector<int>(n_, numeric_limits<int>::max());

    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; ++j) {
        min_each_col_[j] = min(min_each_col_[j], cost[i][j]);
      }
    }
    vector<vector<int>> dp(m_, vector<int>((1 << n_) + 1, -1));

    return rec(0, 0, cost, dp);
  }

private:
  int rec(int cur, int mask, vector<vector<int>> &cost,
          vector<vector<int>> &dp) {
    // 穷举所有从左边到右边的集合，这个时候左边到右边每个节点都有个出度
    // 但是右边到左边不一定，这个步骤就是保证右边的节点也有出度，那怎么
    // 做？其实就是取最小的即可，这就是算 min_each_col_的价值
    if (cur == cost.size()) {
      int take = 0;
      for (int j = 0; j < n_; ++j) {
        if ((mask & (1 << j)) == 0) {
          take += min_each_col_[j];
        }
      }
      return take;
    }

    if (dp[cur][mask] != -1) {
      return dp[cur][mask];
    }

    int ret = numeric_limits<int>::max();
    for (int j = 0; j < n_; ++j) {
      ret = min(ret, cost[cur][j] + rec(cur + 1, mask | (1 << j), cost, dp));
    }

    dp[cur][mask] = ret;

    return ret;
  }

private:
  int m_;
  int n_;
  vector<int> min_each_col_;
};
