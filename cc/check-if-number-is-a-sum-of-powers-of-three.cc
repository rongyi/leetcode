// http://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/
#include "xxx.h"

class Solution {
public:
  bool checkPowersOfThree(int n) {
    int i = 0;
    // int is enough
    while (true) {
      int cur = pow(3, i++);
      if (cur > n) {
        break;
      }
    }
    i--;
    for (; i >= 0; --i) {
      int cur = pow(3, i);
      if (n >= cur) {
        n -= cur;
      }

      if (n == 0) {
        return true;
      }
    }

    return n == 0;
  }
};
