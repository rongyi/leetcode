// https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/
#include "xxx.hpp"

class Solution {
public:
  int smallestValue(int n) {
    int psum = 0;
    for (int i = 2, cp = n; i <= n; ++i) {
      while (cp % i == 0) {
        psum += i;
        cp /= i;
      }
    }
    if (n == psum) {
      return n;
    }

    return smallestValue(psum);
  }
};
