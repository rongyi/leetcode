// http://leetcode.com/problems/power-of-four/description/
#include "xxx.hpp"

class Solution {
public:
  bool isPowerOfFour(int num) {
    if (num <= 0) {
      return false;
    }
    if (num == 1) {
      return true;
    }
    // power of 4 must be power of 2, fast path
    if ((num & (num - 1)) != 0) {
      return false;
    }
    if (num % 4 != 0) {
      return false;
    }
    return isPowerOfFour(num / 4);
  }
};
