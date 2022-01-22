// http://leetcode.com/problems/sign-of-the-product-of-an-array/description/
#include "xxx.hpp"

class Solution {
public:
  int arraySign(vector<int> &nums) {
    // < 0 count
    int ltz = 0;
    for (auto num : nums) {
      if (num == 0) {
        return 0;
      }
      if (num < 0) {
        ltz++;
      }
    }

    if (ltz & 1) {
      return -1;
    }
    return 1;
  }
};
