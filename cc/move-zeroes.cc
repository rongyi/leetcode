// http://leetcode.com/problems/move-zeroes/description/
#include "xxx.hpp"

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int sz = nums.size();
    int j = 0;
    for (int i = 0; i < sz; i++) {
      if (nums[i] != 0) {
        nums[j++] = nums[i];
      }
    }

    fill(nums.begin() + j, nums.end(), 0);
  }
};
