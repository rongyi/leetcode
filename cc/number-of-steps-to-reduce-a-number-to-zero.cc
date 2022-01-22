// http://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/description/
#include "xxx.hpp"

class Solution {
public:
  int numberOfSteps(int num) {
    int ret = 0;
    while (num) {
      ++ret;
      if (num & 1) {
        num--;
      } else {
        num >>= 1;
      }
    }

    return ret;
  }
};
