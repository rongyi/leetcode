// http://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
#include "xxx.h"

class Solution {
public:
  int findNumberOfLIS(vector<int> &nums) {
    const int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> cnt(n, 1);

    int max_len = 0;
    int ret = 0;
    // 思路请参考: longest-increasing-subsequence.cc
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < k; i++) {
        if (nums[i] < nums[k]) {
          // 终止到k的LIS个数是前面比它小的那个字符LIS的cnt汇总
          // e.g. 1 3 3 7
          // 7前面两个3， 每个3前面一个1,所以到7的LIS个数为2
          if (dp[k] == dp[i] + 1) {
            cnt[k] += cnt[i];
          }
          // 需要更新LIS了
          if (dp[k] < dp[i] + 1) {
            dp[k] = dp[i] + 1;
            // 更新LIS的时候，就只是最一开的那个前面LIS统计个数
            cnt[k] = cnt[i];
          }
        }
      }
      if (max_len == dp[k]) {
        ret += cnt[k];
      }
      if (max_len < dp[k]) {
        max_len = dp[k];
        ret = cnt[k];
      }
    }
    return ret;
  }
};
