// http://leetcode.com/problems/unique-paths/description/
#include "xxx.hpp"

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<long long>> dp(m, vector<long long>(n, 0));

    // first line
    for (int j = 0; j < n; ++j) {
      dp[0][j] = 1;
    }
    // first column
    for (int i = 0; i < m; ++i) {
      dp[i][0] = 1;
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]);
      }
    }

    return dp[m - 1][n - 1];
  }
};
