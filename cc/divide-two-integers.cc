// http://leetcode.com/problems/divide-two-integers/description/
#include "xxx.hpp"

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (dividend == numeric_limits<int>::min() && divisor == -1) {
      return numeric_limits<int>::max();
    }
    if (dividend == divisor) {
      return 1;
    }
    bool is_pos = !((dividend > 0) ^ (divisor > 0));
    unsigned int ret = 0;
    unsigned int a = abs(dividend);
    unsigned int b = abs(divisor);

    while (a >= b) {
      int q = 0;
      while (a > (b << (1 + q))) {
        q++;
      }
      ret += (1 << q);
      a = a - (b << q);
    }
    if (is_pos && ret == numeric_limits<unsigned int>::max()) {
      return numeric_limits<int>::max();
    }
    if (is_pos) {
      return ret;
    }
    return -ret;
  }
};
