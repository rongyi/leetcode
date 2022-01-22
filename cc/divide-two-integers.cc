// http://leetcode.com/problems/divide-two-integers/description/
#include "xxx.hpp"

class Solution {
public:
  int divide(int dividend, int divisor) {
    // don not using: * / % and we have - + <<, don't forget the shift operation
    long long ret = 0;
    int sign = 1;
    long long n1 = dividend;
    long long n2 = divisor;
    if (dividend < 0) {
      sign *= -1;
      n1 *= -1;
    }
    if (divisor < 0) {
      sign *= -1;
      n2 *= -1;
    }
    // now we have all postive number
    long long cp = n2;
    int step = 0;
    while (cp < n1) {
      step++;
      cp <<= 1;
    }
    while (n1 >= n2) {
      if (n1 >= cp) {
        n1 -= cp;
        ret += (long long)1 << step;
        if (ret >= numeric_limits<int>::max()) {
          return sign == 1? numeric_limits<int>::max() : numeric_limits<int>::min();
        }
      }
      cp >>= 1;
      step--;
    }

    return (int)ret * sign;
  }
};
int main() {
  Solution so;
  so.divide(10, 3);
}
