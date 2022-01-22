// http://leetcode.com/problems/paint-house-iii/description/
#include "xxx.hpp"

class Solution {
public:
  int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n,
              int target) {
    vector<vector<vector<int>>> dp(
        m + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

    auto ret = dfs(dp, houses, cost, 0, target, 0);
    if (ret > 1000000) {
      return -1;
    }
    return ret;
  }

private:
  int dfs(vector<vector<vector<int>>> &dp, vector<int> &houses,
          vector<vector<int>> &cost, int cur, int target, int last_clr) {
    if (cur >= houses.size() || target < 0) {
      return target == 0 ? target : 1000001;
    }
    if (houses[cur] != 0) {
      // 用掉一个颜色
      return dfs(dp, houses, cost, cur + 1, target - (last_clr != houses[cur]),
                 houses[cur]);
    }
    if (dp[cur][target][last_clr]) {
      return dp[cur][target][last_clr];
    }
    auto ret = 1000001;
    for (auto clr = 1; clr <= cost[cur].size(); ++clr) {
      ret = min(ret, cost[cur][clr - 1] + dfs(dp, houses, cost, cur + 1,
                                              target - (last_clr != clr), clr));
    }

    return dp[cur][target][last_clr] = ret;
  }
};
