// https://leetcode.com/problems/powx-n/description/
#include "xxx.hpp"

class Solution {
public:
  double myPow(double x, int n) {
    long long ln = n;
    if (n < 0) {
      return 1 / pow(x, -ln);
    }
    return pow(x, ln);
  }

private:
  double pow(double x, long long n) {
    if (n == 0) {
      return 1;
    }
    auto half = pow(x, n / 2);
    if (n & 1) {
      return x * half * half;
    }
    return half * half;
  }
};
