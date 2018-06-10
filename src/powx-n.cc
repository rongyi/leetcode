// https://leetcode.com/problems/powx-n/description/
#include "one.h"

class Solution {
public:
  double myPow(double x, int n) {
    if (n < 0) {
      return 1 / pow(x, -n);
    }
    return pow(x, n);
  }

private:
  double pow(double x, int n) {
    if (n == 0) {
      return 1;
    }
    double half = pow(x, n / 2);
    // n is odd
    if (n & 0x1) {
      return x * half * half;
    }
    return half * half;
  }
};
