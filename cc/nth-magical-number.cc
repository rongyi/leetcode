// http://leetcode.com/problems/nth-magical-number/description/
#include "xxx.hpp"

class Solution {
public:
  int nthMagicalNumber(int N, int A, int B) {
    const int mod = pow(10, 9) + 7;
    long lcm = A * B / gcd(A, B);
    long l = 2;
    long r = 1e14;
    while (l < r) {
      long m = l + (r - l) / 2;
      if (m / A + m / B - m / lcm < N) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return l % mod;
  }

  int gcd(int x, int y) {
    int r;
    while (y > 0) {
      r = x % y;
      x = y;
      y = r;
    }
    return x;
  }
};
