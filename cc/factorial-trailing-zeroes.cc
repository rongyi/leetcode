// http://leetcode.com/problems/factorial-trailing-zeroes/description/
#include "xxx.hpp"

class Solution {
public:
  int trailingZeroes(int n) {
    int ret = 0;
    for (long long c = n, d = 5; c / d > 0; d *= 5) {
      ret += c / d;
    }

    return ret;
  }
};
