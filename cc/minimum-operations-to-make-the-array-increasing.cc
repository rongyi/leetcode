// http://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/description/
#include "xxx.hpp"

class Solution {
public:
  int minOperations(vector<int> &nums) {
    int ch_num = 0;
    int prev = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > prev) {
        prev = nums[i];
      } else {
        // expect to prev++, got nums[i], need to incrmt it's delta
        prev++;
        ch_num += (prev - nums[i]);
      }
    }

    return ch_num;
  }
};
