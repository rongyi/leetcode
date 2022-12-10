// https://leetcode.com/problems/minimum-total-distance-traveled/
#include "xxx.hpp"

class Solution {
public:
  long long minimumTotalDistance(vector<int> &robot,
                                 vector<vector<int>> &factory) {
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end());

    vector<int> flat_factories;
    for (auto &f : factory) {
      auto pos = f[0];
      auto cap = f[1];
      for (int i = 0; i < cap; ++i) {
        flat_factories.push_back(pos);
      }
    }
    vector<vector<long long>> dp(
        robot.size() + 1, vector<long long>(flat_factories.size() + 1, -1));

    return dfs(0, 0, robot, flat_factories, dp);
  }

private:
  long long dfs(int ridx, int fidx, vector<int> &robot, vector<int> &factory,
                vector<vector<long long>> &dp) {
    if (ridx >= robot.size()) {
      return 0;
    }
    if (fidx >= factory.size()) {
      return (long long)(1e16);
    }
    if (dp[ridx][fidx] != -1) {
      return dp[ridx][fidx];
    }

    // put current robot to current factory
    long long take = abs(factory[fidx] - robot[ridx]) +
                     dfs(ridx + 1, fidx + 1, robot, factory, dp);
    // ignore current factory
    long long not_take = dfs(ridx, fidx + 1, robot, factory, dp);
    return dp[ridx][fidx] = min(take, not_take);
  }
};
