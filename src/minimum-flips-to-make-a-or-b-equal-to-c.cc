// http://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/
#include "xxx.h"

class Solution {
public:
  int minFlips(int a, int b, int c) {
    int ret = 0;
    // or operation
    for (int i = 0; i < 32; i++) {
      int target = (c >> i) & 1;
      int ca = (a >> i) & 1;
      int cb = (b >> i) & 1;
      if (target == 1) {
        // when target is 1, either ca cb is one will be ok
        // we need flip bit only when both are zero,
        // an we only flip one bit
        if (ca == 0 && cb == 0) {
          ++ret;
        }
      } else {
        // when target is zero, ca cb must be zero
        if (ca) {
          ++ret;
        }
        if (cb) {
          ++ret;
        }
      }
    }

    return ret;
  }
};
