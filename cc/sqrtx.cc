// https://leetcode.com/problems/sqrtx/description/
#include "xxx.hpp"

class Solution {
public:
  int mySqrt(int x) {
    if (x <= 1) {
      return x;
    }
    int l = 0;
    int r = x;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (x / m == m) {
        return m;
      } else if (x / m < m) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    return r;
  }
};
