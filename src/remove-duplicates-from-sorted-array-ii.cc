// http://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
#include "xxx.h"

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    const int n = nums.size();
    if (n < 3) {
      return n;
    }
    int idx = 2;
    for (int i = 2; i < n; ++i) {
      if (nums[i] != nums[idx - 2]) {
        nums[idx++] = nums[i];
      }
    }

    return idx;
  }
};
