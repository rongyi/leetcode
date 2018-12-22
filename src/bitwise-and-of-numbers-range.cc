// http://leetcode.com/problems/bitwise-and-of-numbers-range/description/
#include "xxx.h"

class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
    int shift = 0;
    while (m != n) {
      m >>= 1;
      n >>= 1;
      shift++;
    }
    return m << shift;
  }
};
