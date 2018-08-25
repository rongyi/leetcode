// http://leetcode.com/problems/factorial-trailing-zeroes/description/
#include "one.h"

class Solution {
public:
  int trailingZeroes(int n) {
    int ret = 0;
    while (n) {
      ret += n / 5;
      n /= 5;
    }
    return ret;
  }
};
