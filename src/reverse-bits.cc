// http://leetcode.com/problems/reverse-bits/description/
#include "one.h"

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    int ret = 0;
    int shift = 31;
    while (n) {
      ret |= ((n & 0x1) << shift--);
      n >>= 1;
    }
    return ret;
  }
};
