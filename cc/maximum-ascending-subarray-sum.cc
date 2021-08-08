// http://leetcode.com/problems/maximum-ascending-subarray-sum/description/
#include "xxx.h"

class Solution {
public:
  int maxAscendingSum(vector<int> &nums) {
    int max_sum = nums[0];
    int cur_max = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        cur_max += nums[i];
      } else {
        cur_max = nums[i];
      }

      max_sum = max(max_sum, cur_max);
    }

    return max_sum;
  }
};
