// http://leetcode.com/problems/single-element-in-a-sorted-array/description/
#include "xxx.h"

class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    int ret = 0;
    for (auto i : nums) {
      ret ^= i;
    }

    return ret;
  }
};
