// http://leetcode.com/problems/palindrome-linked-list/description/
#include "simpleone.h"

class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int ret = 0;
    const int m = matrix.size();
    if (m == 0) {
      return ret;
    }
    const int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // 第一行能形成正方形就在于当前节点是不是1
    for (int j =0; j < n; j++) {
      dp[0][j] = matrix[0][j] - '0';
      ret = max(ret, dp[0][j]);
    }
    // 第一列也是
    for (int i = 0; i < m; i++) {
      dp[i][0] = matrix[i][0] - '0';
      ret = max(ret, dp[i][0]);
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] == '1') {
          dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
          ret = max(dp[i][j], ret);
        }
      }
    }

    // return area!
    return ret * ret;
  }
};
