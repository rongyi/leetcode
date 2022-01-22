// http://leetcode.com/problems/smallest-index-with-equal-value/description/
#include "xxx.hpp"

class Solution {
public:
  int smallestEqual(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
      if (i % 10 == nums[i]) {
        return i;
      }
    }

    return -1;
  }
};
