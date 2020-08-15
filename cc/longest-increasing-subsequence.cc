// http://leetcode.com/problems/longest-increasing-subsequence/description/
#include "xxx.h"

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    const int n = nums.size();
    if (n == 0) {
      return 0;
    }
    // dp[i]表示到节点i为止时的最长递增序列
    // 那么要么这个序列为1， ==> 前面找不到比当前节点还小的
    // 要么在前面找到一个值，这个值比当前值小，那么 此时有dp[i] == dp[j] + 1(假设前面找到的那个点为j)
    // 如果在前面找到多个比当前值小呢？ 那就都算一遍找最大值咯，这样算出来就是最大啦
    vector<int> dp(n, 1);

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < k; i++) {
        if (nums[i] < nums[k]) {
          dp[k] = max(dp[k], dp[i] + 1);
        }
      }
    }

    return *max_element(dp.begin(), dp.end());
  }
};
