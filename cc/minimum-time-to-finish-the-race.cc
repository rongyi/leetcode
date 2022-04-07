// https://leetcode.com/problems/minimum-time-to-finish-the-race/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/minimum-time-to-finish-the-race/discuss/1802444/C%2B%2B-Linear-time-DP-with-explanation
  int minimumFinishTime(vector<vector<int>> &tires, int changeTime,
                        int numLaps) {
    int sz = tires.size();
    // when numLaps is small
    // without_change[i][j] : i tire run j laps wihout change --> total time
    vector<vector<long long>> without_change(
        sz, vector<long long>(20 /*put value in [1, 19] */, 2e9));
    for (int i = 0; i < sz; ++i) {
      // tires[0]: base round to finish a lap
      // tires[1]: coeffient
      without_change[i][1] = tires[i][0];
      for (int j = 2; j < 20; ++j) {
        if (without_change[i][j - 1] * tires[i][1] >= 2e9) {
          break;
        }
        without_change[i][j] = without_change[i][j - 1] * tires[i][1];
      }
      // total time is prefix sum
      for (int j = 2; j < 20; ++j) {
        if (without_change[i][j - 1] + without_change[i][j] >= 2e9) {
          break;
        }
        without_change[i][j] += without_change[i][j - 1];
      }
    }

    // dp[i]: min time to finish i laps
    vector<long long> dp(numLaps + 1, 2e9);
    for (int i = 0; i < sz; ++i) {
      // the first round use the fast tire
      dp[1] = min(dp[1], (long long)tires[i][0]);
    }
    for (int x = 1; x <= numLaps; ++x) {
      // x is small enough, so an optimal solution might never changes tires!
      if (x < 20) {
        for (int i = 0; i < sz; ++i) {
          dp[x] = min(dp[x], without_change[i][x]);
        }
      }
      for (int j = x - 1; j > 0 && j >= x - 18; --j) {
        dp[x] = min(dp[x], dp[j] + changeTime + dp[x - j]);
      }
    }

    return dp[numLaps];
  }
};
