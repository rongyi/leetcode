// http://leetcode.com/problems/maximum-population-year/description/

#include "xxx.hpp"

class Solution {
public:
  int maximumPopulation(vector<vector<int>> &logs) {
    const int sz = logs.size();
    vector<int> dp(2051, 0);
    for (int i = 0; i < sz; ++i) {
      dp[logs[i][0]] += 1;
      dp[logs[i][1]] -= 1;
    }
    // line sweep 算法
    for (int i = 1; i < 2051; ++i) {
      dp[i] += dp[i - 1];
    }
    int max_idx = 0;
    int max_value = 0;
    for (int i = 0; i < 2051; ++i) {
      if (dp[i] > max_value) {
        max_value = dp[i];
        max_idx = i;
      }
    }

    return max_idx;
  }
};
