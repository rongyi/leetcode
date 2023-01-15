// https://leetcode.com/problems/count-the-digits-that-divide-a-number/
#include "xxx.hpp"

class Solution {
public:
  int countDigits(int num) {
    int ret = 0;
    int cp = num;

    while (cp) {
      int d = cp % 10;
      if ((num % d) == 0) {
        ret++;
      }
      cp /= 10;
    }

    return ret;
  }
};
