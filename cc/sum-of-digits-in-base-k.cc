// http://leetcode.com/problems/sum-of-digits-in-base-k/description/
#include "xxx.hpp"

class Solution {
public:
  int sumBase(int n, int k) {
    long long base = k;
    while (base <= n) {
      base *= k;
    }
    base /= k;

    int ret = 0;
    while (n) {
      ret += (n / base);
      n %= base;
      base /= k;
    }

    return ret;
  }
};
