// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
#include "xxx.hpp"

class Solution {
public:
  int minBitFlips(int start, int goal) {
    int ret = 0;
    for (int i = 0; i < 31; ++i) {
      if ((start & (1 << i)) != (goal & (1 << i))) {
        ret++;
      }
    }

    return ret;
  }
};
