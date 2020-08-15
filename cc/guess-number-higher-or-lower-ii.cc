// http://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
#include "xxx.h"

class Solution {
public:
  // when we choose number i, the left side still have left ~ i-1 and right side
  // still have i+1 ~ right, we should calculate our worst cost, we can choose
  // the max cost between left part and right part, that is :
  // worst_cost = i + max( cost( left, i-1), cost( i+1, right ) ) ,
  // and we want to find the
  // minimal cost of the worst cost, so we iterate i from left to right,
  // calculate all of the worst_cost value and find the minimal one :
  // min(cur_worst_cost, worst_cost )
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
