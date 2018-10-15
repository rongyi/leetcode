// http://leetcode.com/problems/number-of-1-bits/description/
#include "one.h"
class Solution {
public:
  int hammingWeight(uint32_t n) {
    int ret = 0;
    while (n) {
      if (n & 0x1) {
        ret++;
      }
      n >>= 1;
    }
    return ret;
  }
};
