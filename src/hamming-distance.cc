// http://leetcode.com/problems/hamming-distance/description/
#include "xxx.h"

class Solution {
public:
  int hammingDistance(int x, int y) {
    int ret = 0;
    auto val = x ^ y;

    while (val != 0) {
      ret++;
      val &= val - 1;
    }

    return ret;
  }
};
