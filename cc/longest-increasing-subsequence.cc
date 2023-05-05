// http://leetcode.com/problems/longest-increasing-subsequence/description/
#include "xxx.hpp"

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int sz = nums.size();
    vector<int> dp(sz, 1);
    int ret = 1;
    for (int j = 1; j < sz; j++) {
      for (int i = 0; i < j; i++) {
        // for every element, if we find one smaller before
        // then we can construct one more lis
        if (nums[j] > nums[i]) {
          dp[j] = max(dp[j], 1 + dp[i]);
          ret = max(ret, dp[j]);
        }
      }
    }

    return ret;
  }
};
