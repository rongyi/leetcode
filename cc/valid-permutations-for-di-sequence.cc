// http://leetcode.com/problems/valid-permutations-for-di-sequence/description/
#include "xxx.h"

class Solution {
public:
  int numPermsDISequence(string S) {
    int n = S.size();
    int m = pow(10, 9) + 7;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= i; j++) {
        if (S[i - 1] == 'D') {
          for (int k = j; k <= i - 1; k++) {
            dp[i][j] = dp[i][j] % m + dp[i - 1][k] % m;
          }
        } else {
          for (int k = 0; k <= j - 1; k++) {
            dp[i][j] = dp[i][j] % m + dp[i - 1][k] % m;
          }
        }
      }
    }

    int ret = 0;
    for (int i = 0; i <= n; i++) {
      ret = ret % m + dp[n][i] % m;
    }

    return ret % m;
  }
};
