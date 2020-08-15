// http://leetcode.com/problems/out-of-boundary-paths/description/
#include "xxx.h"

class Solution {
public:
  int findPaths(int m, int n, int N, int x, int y) {
    vector<vector<vector<long long>>> dp(
        N + 1, vector<vector<long long>>(m, vector<long long>(n, 0)));
    for (int step = 1; step <= N; step++) {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          // 在边上，一脚踢出去，不在的话可以往四个方向踢
          dp[step][i][j] = ((i == 0 ? 1 : dp[step - 1][i - 1][j]) +
                            (i == m - 1 ? 1 : dp[step - 1][i + 1][j]) +
                            (j == 0 ? 1 : dp[step - 1][i][j - 1]) +
                            (j == n - 1 ? 1 : dp[step - 1][i][j + 1])) %
                           1000000007;
        }
      }
    }
    return dp[N][x][y];
  }
};
