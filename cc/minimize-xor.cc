// https://leetcode.com/problems/minimize-xor/
#include "xxx.hpp"

class Solution {
public:
  int minimizeXor(int num1, int num2) {
    int one1 = countbit(num1);
    int one2 = countbit(num2);
    // to make sure the xor with num1 is minimal
    // we pick all the one1 from left for total: min(one1, one2)
    // if there're some left 1
    // we make all 0 to 1 from right
    int ret = 0;
    for (int i = 31, j = min(one1, one2); i >= 0 && j > 0; --i) {
      if ((num1 & (1 << i)) != 0) {
        ret |= (1 << i);
        j--;
      }
    }
    if (one2 > one1) {
      int zerotoone = one2 - one1;
      for (int i = 0; i <= 31 && zerotoone > 0; ++i) {
        // flip 0 to 1
        if ((num1 & (1 << i)) == 0) {
          ret |= (1 << i);
          zerotoone--;
        }
      }
    }

    return ret;
  }

private:
  int countbit(int n) {
    int ret = 0;
    while (n) {
      n &= n - 1;
      ret++;
    }

    return ret;
  }
};
