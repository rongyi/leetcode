// http://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/
#include "xxx.hpp"

class Solution {
public:
  int numSubarrayBoundedMax(vector<int> &nums, int left, int right) {
    return count(nums, right) - count(nums, left - 1);
  }

  int count(vector<int> &nums, int bound) {
    int ret = 0;
    int acc = 0;
    for (auto &num : nums) {
      if (num <= bound) {
        acc += 1;
      } else {
        acc = 0;
      }
      ret += acc;
    }

    return ret;
  }
};

