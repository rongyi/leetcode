// http://leetcode.com/problems/house-robber-ii/description/
#include "simpleone.h"

class Solution {
public:
  int rob(vector<int> &nums) {
    const int n = nums.size();
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return nums[0];
    }
    return max(doRobber(nums, 0, n - 1), doRobber(nums, 1, n));
  }

  int doRobber(vector<int> &nums, int left, int right) {
    const int n = right - left;
    if (n <= 1) {
      return nums[left];
    }
    vector<int> dp(n, 0);
    dp[0] = nums[left];
    dp[1] = max(dp[0], nums[left + 1]);
    for (int i = 2; i < n; i++) {
      dp[i] = max(dp[i - 1], nums[left + i] + dp[i - 2]);
    }

    return dp[n - 1];
  }
};
