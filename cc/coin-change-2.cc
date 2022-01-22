// http://leetcode.com/problems/coin-change-2/description/
#include "xxx.hpp"

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    const int n = coins.size();
    if (amount == 0) {
      return 1;
    }
    if (n == 0) {
      return 0;
    }

    // i ==> 用到的ith硬币
    // j ==> 加起来的amount
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    // amount为0，就是一个空集
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      // amount为0，空集满足
      dp[i][0] = 1;
      for (int j = 1; j <= amount; ++j) {
        // 用前面i个硬币凑到和为j
        // 前面i个硬币的最后一个来说，可取可不取
        // 1. 不取，那么前面 i - 1 个硬币凑出和为 j 有多少种方法，那么 dp[i][j] 就有多少种
        //    也即此时dp[i][j] == dp[i - 1][j]
        // 2. 取了，那么dp[i][j - coints[i - 1]](amount为减去最后一个元素)包含i在内和为 j - coins[i - 1]
        //    有多少种方法
        dp[i][j] =
            dp[i - 1][j] + (j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0);
      }
    }
    return dp[n][amount];
  }
};
