// http://leetcode.com/problems/power-of-two/description/
#include "simpleone.h"

class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }
    return ((n & (n - 1)) == 0);
  }
};
