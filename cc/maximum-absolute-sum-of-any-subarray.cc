// http://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/
#include "xxx.h"

class Solution {
public:
  int maxAbsoluteSum(vector<int> &nums) {
    int max_sum = 0;
    int min_sum = 0;
    int ret = 0;
    // 算区间最大值最小值，然后算abs最大的
    for (auto n : nums) {
      max_sum = max(0, n + max_sum);
      min_sum = min(0, n + min_sum);
      ret = max(ret, max(max_sum, abs(min_sum)));
    }
    return ret;
  }
};
