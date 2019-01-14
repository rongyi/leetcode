// http://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
#include "xxx.h"

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {

    const int n = nums.size();
    if (n <= 1) {
      return n;
    }
    // uniq index
    int ui = 1;
    for (int i = 1; i < n; ++i) {
      if (nums[i] != nums[ui - 1]) {
        nums[ui++] = nums[i];
      }
    }
    return ui;
  }
};
