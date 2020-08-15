// http://leetcode.com/problems/min-cost-climbing-stairs/description/
#include "xxx.h"

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    // cost will have a length in the range [2, 1000]
    const int n = cost.size();
    vector<int> dp(n, 0);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; i++) {
      dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    return min(dp[n - 1], dp[n - 2]);
  }
};
