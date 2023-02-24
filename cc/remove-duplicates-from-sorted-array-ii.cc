// http://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
#include "xxx.hpp"

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int sz = nums.size();
    if (sz < 3) {
      return sz;
    }
    int idx = 2;
    for (int i = 2; i < sz; i++) {
      if (nums[idx - 2] != nums[i]) {
        nums[idx++] = nums[i];
      }
    }
    return idx;
  }
};
