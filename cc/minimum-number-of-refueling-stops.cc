// http://leetcode.com/problems/minimum-number-of-refueling-stops/description/
#include "xxx.h"

class Solution {
public:
  // dp[t] means the furthest distance that we can get with t times of
  // refueling.
  int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
    // if the current distance dp[t] >= s[i][0], we can refuel:
    // dp[t + 1] = max(dp[t + 1], dp[t] + s[i][1])
    long dp[501] = {startFuel};
    for (int i = 0; i < stations.size(); i++) {
      // 当前能开的距离包含了这个加油站
      for (int t = i; t >= 0 && dp[t] >= stations[i][0]; --t) {
        dp[t + 1] = max(dp[t + 1], dp[t] + stations[i][1]);
      }
    }
    for (int t = 0; t <= stations.size(); ++t) {
      if (dp[t] >= target) {
        return t;
      }
    }

    return -1;
  }
};
