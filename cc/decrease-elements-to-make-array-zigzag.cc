// http://leetcode.com/problems/decrease-elements-to-make-array-zigzag/description/
#include "xxx.hpp"

class Solution {
public:
  // only one operation: decrease
  // either decrease odd number or event number
  int movesToMakeZigzag(vector<int> &nums) {
    int down_odd = 0;
    int down_even = 0;
    if (nums.size() <= 1) {
      return 0;
    }

    for (int i = 1; i < nums.size(); i += 2) {
      if (i == nums.size() - 1) {
        if (nums[i - 1] <= nums[i]) {
          down_odd += (nums[i] - nums[i - 1] + 1);
        }
      } else {
        // well formated should be like 3 2 3
        // current node be lower between its neighbor
        if (!(nums[i - 1] > nums[i] && nums[i] < nums[i + 1])) {
          down_odd += nums[i] - min(nums[i - 1], nums[i + 1]) + 1;
        }
      }
    }

    for (int i = 0; i < nums.size(); i += 2) {
      if (i == 0) {
        if (nums[i] >= nums[i + 1]) {
          down_even += nums[i] - nums[i + 1] + 1;
        }
      } else if (i == nums.size() - 1) {
        if (nums[i - 1] <= nums[i]) {
          down_even += nums[i] - nums[i - 1] + 1;
        }
      } else {
        // well formated should be like 3 2 3
        // current node be lower between its neighbor
        if (!(nums[i - 1] > nums[i] && nums[i] < nums[i + 1])) {
          down_even += nums[i] - min(nums[i - 1], nums[i + 1]) + 1;
        }
      }
    }

    return min(down_odd, down_even);
  }
};
