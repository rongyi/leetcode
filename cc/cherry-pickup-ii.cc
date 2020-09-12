// http://leetcode.com/problems/cherry-pickup-ii/description/
#include "xxx.h"

class Solution {
public:
  int cherryPickup(vector<vector<int>> &grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    vector<vector<vector<int>>> dp(m,
                                   vector<vector<int>>(n, vector<int>(n, -1)));

    return dfs(grid, dp, m, n, 0, 0, n - 1);
  }

  int dfs(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int m,
          int n, int cur_row, int rob_col1, int rob_col2) {
    if (cur_row == m) {
      return 0;
    }
    if (dp[cur_row][rob_col1][rob_col2] != -1) {
      return dp[cur_row][rob_col1][rob_col2];
    }
    int ret = 0;
    for (int i = -1; i <= 1; ++i) {
      for (int j = -1; j <= 1; ++j) {
        int nc1 = rob_col1 + i;
        int nc2 = rob_col2 + j;
        if (nc1 < 0 || nc1 >= n || nc2 < 0 || nc2 >= n) {
          continue;
        }
        ret = max(ret, dfs(grid, dp, m, n, cur_row + 1, nc1, nc2));
      }
    }

    int chery = (rob_col1 == rob_col2
                     ? grid[cur_row][rob_col1]
                     : grid[cur_row][rob_col1] + grid[cur_row][rob_col2]);
    dp[cur_row][rob_col1][rob_col2] = ret + chery;

    return dp[cur_row][rob_col1][rob_col2];
  }
};
