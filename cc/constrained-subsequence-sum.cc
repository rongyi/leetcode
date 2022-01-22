// http://leetcode.com/problems/constrained-subsequence-sum/description/
#include "xxx.hpp"

class Solution {
public:
  // subsequence中的相邻元素在原有数组中的位置距离不能超过K
  int constrainedSubsetSum(vector<int> &nums, int k) {
    const int n = nums.size();
    vector<int> dp(n, 0);
    deque<int> q;
    int ret = numeric_limits<int>::min();

    for (int i = 0; i < n; ++i) {
      int cur_max = max(0, q.empty() ? 0 : dp[q.front()]);
      dp[i] = nums[i] + cur_max;
      ret = max(ret, dp[i]);
      // deq里小的全走开
      while (!q.empty() && dp[i] >= dp[q.back()]) {
        q.pop_back();
      }
      q.push_back(i);
      // 是为下一轮循环准备的，所以 + 1
      if (i - q.front() + 1 > k) {
        q.pop_front();
      }
    }

    return ret;
  }
};
