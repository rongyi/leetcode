// http://leetcode.com/problems/reverse-bits/description/
#include "xxx.hpp"

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    for (int i = 0; i < 32; i++) {
      ret |= ((n & (1 << i)) != 0) << (32 - i - 1);
    }

    return ret;
  }
};
