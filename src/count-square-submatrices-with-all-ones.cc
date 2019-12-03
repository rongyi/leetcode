// http://leetcode.com/problems/count-square-submatrices-with-all-ones/description/
#include "xxx.h"

class Solution {
public:
  int countSquares(vector<vector<int>> &matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int ret = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j]) {
          dp[i + 1][j + 1] = 1 + min(dp[i][j + 1], min(dp[i][j], dp[i + 1][j]));
          ret += dp[i + 1][j + 1];
        }
      }
    }

    return ret;
  }
};
