// http://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/description/
#include "xxx.hpp"

class Solution {
public:
  int ways(vector<string> &pizza, int k) {
    const int m = pizza.size();
    const int n = pizza[0].size();

    // 初始都是invalid状态-1
    vector<vector<vector<int>>> dp(k,
                                   vector<vector<int>>(m, vector<int>(n, -1)));
    vector<vector<int>> prefix_sum(m + 1, vector<int>(n + 1, 0));

    // 切完都是看右下角这块还是否有苹果可切，prefix_sum算的就是这右下角
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        prefix_sum[i][j] = prefix_sum[i + 1][j] + prefix_sum[i][j + 1] -
                           prefix_sum[i + 1][j + 1] + (pizza[i][j] == 'A');
      }
    }

    return dfs(m, n, k - 1, 0, 0, dp, prefix_sum);
  }

private:
  int dfs(int m, int n, int k, int cur_row, int cur_col,
          vector<vector<vector<int>>> &dp, vector<vector<int>> &prefix_sum) {
    // 无苹果可切
    if (prefix_sum[cur_row][cur_col] == 0) {
      return 0;
    }
    // 切完了，发现一个valid组合
    if (k <= 0) {
      return 1;
    }
    if (dp[k][cur_row][cur_col] != -1) {
      return dp[k][cur_row][cur_col];
    }
    int ret = 0;
    // 试试下刀的地方，切一遭走起！
    // 横着切
    for (int i = cur_row + 1; i < m; ++i) {
      // 什么情况下可以下刀？ ==> 被划开的上半部分有苹果
      if (prefix_sum[cur_row][cur_col] - prefix_sum[i][cur_col] > 0) {
        ret = (ret + dfs(m, n, k - 1, i, cur_col, dp, prefix_sum)) % 1000000007;
      }
    }

    // 竖着切
    for (int j = cur_col + 1; j < n; ++j) {
      // 下刀条件和横着的类似==> 被划开的左半边有苹果
      if (prefix_sum[cur_row][cur_col] - prefix_sum[cur_row][j] > 0) {
        ret = (ret + dfs(m, n, k - 1, cur_row, j, dp, prefix_sum)) % 1000000007;
      }
    }

    return dp[k][cur_row][cur_col] = ret;
  }
};
