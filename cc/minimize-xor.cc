// https://leetcode.com/problems/minimize-xor/
#include "xxx.hpp"

class Solution {
public:
  int minimizeXor(int num1, int num2) {
    int one1 = countbit(num1);
    int one2 = countbit(num2);
    int ret = 0;
    for (int i = 31, j = min(one1, one2); i >= 0 && j > 0; i--) {
      if ((num1 & (1 << i)) != 0) {
        ret |= (1 << i);
        j--;
      }
    }
    if (one2 > one1) {
      int flipcount = one2 - one1;
      for (int i = 0; i <= 31 && flipcount > 0; ++i) {
        if ((num1 & (1 << i)) == 0) {
          ret |= (1 << i);
          flipcount--;
        }
      }
    }

    return ret;
  }

private:
  int countbit(int num) {
    int ret = 0;
    while (num) {
      ret++;
      num &= num - 1;
    }

    return ret;
  }
};
