// http://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/
#include "xxx.h"

class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
    const int n = nums.size();
    // dp[i] 表示长度为k，结尾index为i的和
    // 问题归结为 dp[x] + dp[y] + dp[z] 最大
    // y <= z - k ==> y + k <= z
    // x <= y - k ==> x + k <= y
    // 凑一起
    // x + k + k <= y + k <= z
    // x + 2k <= y + k <= z
    // 这样的index需求下求最大
    // candidt_idx 缓存x y z坐标
    // cur 缓存三个数组的和
    // 其中：cur[0] == 第一个数组 cur[1] == 第一 + 第二个数组
    // cur[2] == 第一 + 第二 + 第三
    vector<vector<int>> candidt_idx(3, vector<int>{});
    vector<int> cur(3, 0);
    vector<int> dp(n, 0);

    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      if (i >= k - 1) {
        dp[i] = sum;
        sum -= nums[i - k + 1];
        if (i >= 3 * k - 1) {
          if (dp[i - k - k] > cur[0]) {
            cur[0] = dp[i - k - k];
            candidt_idx[0] = {i - k - k};
          }
          if (dp[i - k] + cur[0] > cur[1]) {
            cur[1] = dp[i - k] + cur[0];
            candidt_idx[1] = {candidt_idx[0][0], i - k};
          }
          if (dp[i] + cur[1] > cur[2]) {
            cur[2] = cur[1] + dp[i];
            candidt_idx[2] = {candidt_idx[1][0], candidt_idx[1][1], i};
          }
        }
      }
    }

    return {candidt_idx[2][0] - k + 1, candidt_idx[2][1] - k + 1,
            candidt_idx[2][2] - k + 1};
  }
};
