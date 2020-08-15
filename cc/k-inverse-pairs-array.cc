// http://leetcode.com/problems/k-inverse-pairs-array/description/
#include "xxx.h"

class Solution {
public:
  int kInversePairs(int n, int k) {
    int mod = pow(10, 9) + 7;
    int sum = n * (n - 1) / 2;
    if (k > sum || k < 0) {
      return 0;
    }
    if (k == 0 || k == sum) {
      return 1;
    }
    vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));
    dp[0][0] = 1; // mean sum of arrays that consist of 1 with 0 inverse pairs
    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= k; j++) {
        for (int m = j; m >= 0 && m >= (j - i); m--) {
          dp[i][j] += dp[i - 1][m];
        }
        dp[i][j] %= mod;
      }
    }
    return (int)dp[n - 1][k];
  }
};
