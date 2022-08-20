// https://leetcode.com/problems/count-the-number-of-ideal-arrays/
#include "xxx.hpp"

class Solution {
public:
  int idealArrays(int n, int maxValue) {
    comb_ = vector<vector<int>>(n, vector<int>(15, -1));
    vector<vector<int>> dp(maxValue + 1, vector<int>(15, 0));
    dp[1][1] = 1;
    for (int i = 2; i <= maxValue; ++i) {
      dp[i][1] = 1;
      for (int j = 1; j <= int(sqrt(i)); ++j) {
        int j2 = i / j;
        if (j2 * j == i) {
          for (int k = 1; k < 14; ++k) {
            dp[i][k + 1] += dp[j][k];
          }
          if (j2 != i && j2 != j) {
            for (int k = 1; k < 14; ++k) {
              dp[i][k + 1] += dp[j2][k];
            }
          }
        }
      }
    }

    vector<int> whole(15, 0);
    for (int i = 1; i < 15; ++i) {
      int w = 0;
      for (int j = 1; j <= maxValue; ++j) {
        w += dp[j][i];
      }
      whole[i] = w;
    }
    int ret = 0;
    for (int i = 1; i <= min(n, 14); ++i) {
      ret = (0ll + ret + 1ll * choosenofk(n - 1, i - 1) * whole[i]) % mod_;
    }

    return ret;
  }

private:
  int choosenofk(int n, int k) {
    if (comb_[n][k] != -1) {
      return comb_[n][k];
    }
    if (k == 0) {
      comb_[n][k] = 1;
      return comb_[n][k];
    }
    if (k == 1) {
      comb_[n][k] = n;
      return comb_[n][k];
    }
    if (n == k) {
      comb_[n][k] = 1;
      return comb_[n][k];
    }
    comb_[n][k] =
        (0ll + choosenofk(n - 1, k - 1) + choosenofk(n - 1, k)) % mod_;

    return comb_[n][k];
  }

private:
  int mod_ = 1e9 + 7;
  vector<vector<int>> comb_;
};

