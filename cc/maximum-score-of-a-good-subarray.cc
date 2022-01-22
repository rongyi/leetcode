// http://leetcode.com/problems/maximum-score-of-a-good-subarray/description/
#include "xxx.hpp"

class Solution {
public:
  int maximumScore(vector<int> &nums, int k) {
    int ret = nums[k];
    int min_range = nums[k];
    int i = k;
    int j = k;
    const int n = nums.size();

    // 总是尽可能的往大的那边靠
    while (i > 0 || j < n - 1) {
      if ((i > 0 ? nums[i - 1] : 0) < (j < n - 1 ? nums[j + 1] : 0)) {
        min_range = min(min_range, nums[++j]);
      } else {
        min_range = min(min_range, nums[--i]);
      }
      ret = max(ret, min_range * (j - i + 1));
    }

    return ret;
  }
};
