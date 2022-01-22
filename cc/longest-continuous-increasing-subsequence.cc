// http://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
#include "xxx.hpp"

class Solution {
public:
  int findLengthOfLCIS(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    const int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
      if (nums[i - 1] < nums[i]) {
        dp[i] += dp[i - 1];
      }
    }

    return *max_element(dp.begin(), dp.end());
  }
};
