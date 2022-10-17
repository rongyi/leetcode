// https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/
#include "xxx.hpp"

class Solution {
public:
  int numberOfWays(int startPos, int endPos, int k) {
    return dfs(k, abs(startPos - endPos));
  }

private:
  int dfs(int k, int d) {
    // k step can reach distance k at most
    if (d >= k) {
      return d == k;
    }
    if (dp_[k][d] == 0) {
      dp_[k][d] =
          // or use -1 for all initial value, and check -1
          (1 + dfs(k - 1, d + 1) + dfs(k - 1, abs(d - 1))) % int(1e9 + 7);
    }

    return dp_[k][d] - 1;
  }

private:
  // k steps to reach distance d
  // so we can use k - 1 step to d's both side
  // dp_[k][d] == dp[k - 1][d -1] + dp[k - 1][d + 1];
  int dp_[1001][1001] = {};
};

