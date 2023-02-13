// http://leetcode.com/problems/jump-game-ii/description/
#include "xxx.hpp"

class Solution {
public:
  int jump(vector<int> &nums) {
    vector<int> dp(nums.size(), nums.size());
    return dfs(nums, 0, dp);
  }

private:
  int dfs(vector<int> &nums, int pos, vector<int> &dp) {
    if (pos >= nums.size() - 1) {
      return 0;
    }
    if (dp[pos] != nums.size()) {
      return dp[pos];
    }
    int min_step = nums.size();
    for (int i = 1; i <= nums[pos]; i++) {
      min_step = min(min_step, 1 + dfs(nums, pos + i, dp));
    }

    dp[pos] = min_step;
    return dp[pos];
  }
};
