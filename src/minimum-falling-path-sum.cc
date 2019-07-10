// http://leetcode.com/problems/minimum-falling-path-sum/description/
#include "xxx.h"

class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &A) {
    const int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, numeric_limits<int>::max()));
    int ret = numeric_limits<int>::max();

    // first row value copy to dp
    for (int j = 0; j < n; j++) {
      dp[0][j] = A[0][j];
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < n; j++) {
        auto cur = A[i][j];
        if (j == 0) {
          // from top and top right
          dp[i][j] = min(dp[i][j], dp[i - 1][j] + cur);
          dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + cur);
        } else if (j == n - 1) {
          // from top and top left
          dp[i][j] = min(dp[i][j], dp[i - 1][j] + cur);
          dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + cur);
        } else {
          // from three column
          dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + cur);
          dp[i][j] = min(dp[i][j], dp[i - 1][j] + cur);
          dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + cur);
        }
      }
    }

    // last row of dp
    for (auto v : dp[n - 1]) {
      ret = min(ret, v);
    }
    return ret;
  }
};
