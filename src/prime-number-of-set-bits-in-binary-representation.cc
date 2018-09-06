// http://www.lintcode.com/zh-cn/problem/prime-number-of-set-bits-in-binary-representation
#include "one.h"

class Solution {
public:
  int countPrimeSetBits(int L, int R) {
    unordered_set<int> prime{2, 3, 5, 7, 11, 13, 17, 19};
    int ret = 0;
    for (int i = L; i <= R; ++i) {
      ret += prime.count(countBit(i));
    }
    return ret;
  }

private:
  int countBit(int i) {
    int ret = 0;
    while (i) {
      if ((i & 1) == 1) {
        ++ret;
      }
      i >>= 1;
    }
    return ret;
  }
};
