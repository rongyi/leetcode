// http://leetcode.com/problems/sum-of-two-integers/description/
#include "xxx.hpp"

class Solution {
public:
  // do not use + or -
  int getSum(int a, int b) {
    int carry = 0;
    int ret = 0;

    for (unsigned mask = 1; mask; mask <<= 1) {
      // 自己卡在这里的表达怎么算
      ret |= (a ^ b ^ carry) & mask;
      carry = ((a & b) | ((a ^ b) & carry)) << 1;
    }

    return ret;
  }
};
