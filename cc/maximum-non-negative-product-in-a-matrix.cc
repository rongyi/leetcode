// http://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/
#include "xxx.hpp"

class Solution {
public:
  int maxProductPath(vector<vector<int>> &grid) {
    const int mod = pow(10, 9) + 7;
    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<pair<long, long>>> dp(m, vector<pair<long, long>>(n, {0, 0}));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 && j == 0) {
          dp[i][j] = {grid[i][j], grid[i][j]};
        } else {
          // 最上面选左边的
          auto &up = i > 0 ? dp[i - 1][j] : dp[i][j - 1];
          // 最左边选上面的
          auto &left = j > 0 ? dp[i][j - 1] : dp[i - 1][j];
          auto first = max(up.first, left.first);
          auto second = min(up.second, left.second);
          if (grid[i][j] < 0) {
            swap(first, second);
          }
          dp[i][j] = {grid[i][j] * first, grid[i][j] * second};
        }
      }
    }
    if (dp[m - 1][n - 1].first < 0) {
      return -1;
    }

    return dp[m - 1][n - 1].first % mod;
  }
};
