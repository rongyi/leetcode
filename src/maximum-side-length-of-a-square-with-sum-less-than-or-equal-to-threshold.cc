// http://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/
#include "xxx.h"

class Solution {
public:
  int maxSideLength(vector<vector<int>> &mat, int threshold) {
    const int m = mat.size();
    const int n = mat[0].size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // prefix sum
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] =
            mat[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
      }
    }

    int len = 0;

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        int r = min(i, j);
        for (int k = 1; k <= r; k++) {
          int val = dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k];
          if (val <= threshold) {
            len = max(len, k);
          }
        }
      }
    }

    return len;
  }
};
