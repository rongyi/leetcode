// http://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/
#include "xxx.h"

class Solution {
public:
  int numRollsToTarget(int d, int f, int target) {
    const int mod = pow(10, 9) + 7;
    // dp[i][j] i dice can roll to sum j
    vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= d; ++i) {
      for (int j = 1; j <= target; ++j) {
        // j is too big, can not reach
        if (j > i * f) {
          break;
        }
        for (int k = 1; k <= f && k <= j; ++k) {
          // i - 1 dice can roll to sum j - k
          dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
        }
      }
    }
    return dp[d][target];
  }
};
