// http://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
#include "xxx.h"

class Solution {
public:
  int getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    return recur(1, n, dp);
  }
private:
  int recur(int l, int r, vector<vector<int>> &dp) {
    if (l >= r) {
      return 0;
    }
    if (dp[l][r]) {
      return dp[l][r];
    }
    int ret = numeric_limits<int>::max();
    for (int i = l; i <= r; i++) {
      ret = min(ret, i + max(recur(l, i - 1, dp), recur(i + 1, r, dp)));
    }
    dp[l][r] = ret;

    return ret;
  }
};
