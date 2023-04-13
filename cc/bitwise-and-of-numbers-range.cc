// http://leetcode.com/problems/bitwise-and-of-numbers-range/description/
#include "xxx.hpp"

class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
    // a and b will not bigger than a or b
    while (m < n) {
      n = n & (n - 1);
    }

    return n;
  }
};
