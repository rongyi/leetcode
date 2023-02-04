// http://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
#include "xxx.hpp"

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int sz = nums.size();
    // uniq index
    int ui = 1;

    for (int i = 1; i < sz; ++i) {
      if (nums[i] != nums[ui - 1]) {
        nums[ui++] = nums[i];
      }
    }

    return ui;
  }
};
