// http://leetcode.com/problems/house-robber/description/
#include "xxx.hpp"

class Solution {
public:
  int rob(vector<int> &nums) {
    int sz = nums.size();

    vector<int> dp(sz + 1, 0);
    dp[1] = nums[0];
    for (int i = 1; i < sz; i++) {
      dp[i + 1] = max(dp[i - 1] + nums[i], dp[i]);
    }

    return dp[sz];
  }
};

