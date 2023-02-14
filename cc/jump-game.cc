// http://leetcode.com/problems/jump-game/description/
#include "xxx.hpp"

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int max_reach = 0;
    for (int i = 0; i <= max_reach; i++) {
      max_reach = max(max_reach, i + nums[i]);
      if (max_reach >= nums.size() - 1) {
        return true;
      }
    }
    return false;
  }
  bool recur(vector<int> &nums, int cur, vector<int> &dp) {
    if (cur >= nums.size() - 1) {
      dp[cur] = true;
      return dp[cur];
    }
    if (dp[cur] != -1) {
      return dp[cur];
    }
    for (int i = 1; i <= nums[cur]; i++) {
      if (recur(nums, cur + i, dp)) {
        dp[cur] = true;
        return true;
      }
    }
    dp[cur] = false;
    return dp[cur];
  }
};

