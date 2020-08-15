// http://leetcode.com/problems/matrix-block-sum/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K) {
    const int m = mat.size();
    const int n = mat[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    vector<vector<int>> ret(m, vector<int>(n, 0));

    // prefix sum yo!
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] =
            dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        auto rx = min(m - 1, i + K);
        auto ry = min(n - 1, j + K);

        auto lx = max(0, i - K);
        auto ly = max(0, j - K);
        // now we get the rectange cordinate
        auto sum =
            dp[rx + 1][ry + 1] + dp[lx][ly] - dp[rx + 1][ly] - dp[lx][ry + 1];
        ret[i][j] = sum;
      }
    }

    return ret;
  }
};
