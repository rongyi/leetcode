// http://leetcode.com/problems/maximum-subarray/description/
#include "xxx.hpp"

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int sz = nums.size();
    int cur_sum = 0;
    int max_sum = nums[0];

    for (int i = 0; i < sz; i++) {
      auto plus = cur_sum + nums[i];
      if (plus > nums[i]) {
        cur_sum = plus;
      } else {
        cur_sum = nums[i];
      }
      max_sum = max(max_sum, cur_sum);
    }

    return max_sum;
  }
};

