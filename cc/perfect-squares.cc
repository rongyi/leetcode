// http://leetcode.com/problems/perfect-squares/description/
#include "xxx.h"

class Solution {
public:
  int numSquares(int n) {
    if (n <= 0) {
      return 0;
    }
    // 找出最少的，平方数的和为n的数
    vector<int> dp(n + 1, numeric_limits<int>::max());
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j * j <= i; j++) {
        // For each i, it must be the sum of some number (i - j*j) and
        // a perfect square number (j*j).
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }
    return dp[n];
  }
};
