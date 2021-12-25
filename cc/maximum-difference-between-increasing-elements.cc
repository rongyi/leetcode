// https://leetcode.com/problems/maximum-difference-between-increasing-elements/
#include "xxx.h"

class Solution {
public:
  int maximumDifference(vector<int> &nums) {
    int sz = nums.size();
    int ret = 0;
    int right_max = nums[sz - 1];
    for (int i = sz - 2; i >= 0; --i) {
      ret = max(ret, right_max - nums[i]);
      right_max = max(right_max, nums[i]);
    }
    if (ret == 0) {
      return -1;
    }
    return ret;
  }
};
