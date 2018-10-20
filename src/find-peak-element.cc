// http://leetcode.com/problems/find-peak-element/description/
#include "one.h"

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < nums[i - 1]) {
        return i - 1;
      }
    }
    return nums.size() - 1;
  }
};
