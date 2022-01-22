// http://leetcode.com/problems/remove-element/description/
#include "xxx.hpp"

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int ui = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        nums[ui++] = nums[i];
      }
    }
    return ui;
  }
};
