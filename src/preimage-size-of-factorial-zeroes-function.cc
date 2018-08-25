// http://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/description/
#include "one.h"
class Solution {
public:
  int preimageSizeFZF(int K) {
    long left = 0;
    long right = 5L * (K + 1);
    while (left < right) {
      long mid = left + (right - left) / 2;
      long cnt = tzero(mid);
      if (cnt == K) {
        return 5;
      } else if (cnt < K) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return 0;
  }

private:
  long tzero(long x) {
    long ret = 0;
    for (; x > 0; x /= 5) {
      ret += x / 5;
    }
    return ret;
  }
};
