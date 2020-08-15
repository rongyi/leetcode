// http://leetcode.com/problems/dice-roll-simulation/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/dice-roll-simulation/discuss/404188/C%2B%2B-DP-solution
  int dieSimulator(int n, vector<int> &rollMax) {
    const int mod = pow(10, 9) + 7;
    // dp[i][j][k] 第i次扔，最后那个数字是j，并且已经连续出现k次了
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(6, vector<int>(16, 0)));

    for (int i = 0; i < 6; ++i) {
      dp[0][i][1] = 1;
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < 6; ++j) {
        // dp[i][j][1] = sum(dp[i - 1][except j][1 to rollMax[j]])
        for (int k = 0; k < 6; ++k) {
          if (k == j) {
            continue;
          }
          for (int m = 1; m <= rollMax[k]; ++m) {
            dp[i][j][1] = (dp[i][j][1] + dp[i - 1][k][m]) % mod;
          }
        }
        for (int m = 2; m <= rollMax[j]; ++m) {
          dp[i][j][m] = dp[i - 1][j][m - 1];
        }
      }
    }

    int ret = 0;
    for (int i = 0; i < 6; ++i) {
      for (int j = 1; j <= rollMax[i]; ++j) {
        ret = (ret + dp[n - 1][i][j]) % mod;
      }
    }
    return ret;
  }
};
