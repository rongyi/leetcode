// http://leetcode.com/problems/ugly-number-iii/description/
#include "xxx.h"
class Solution {
public:
  int nthUglyNumber(int k, int A, int B, int C) {
    int lo = 1;
    int hi = 2 * (int)1e9;
    long a = (long)A;
    long b = (long)B;
    long c = (long)C;
    long ab = a * b / __gcd(a, b);
    long bc = b * c / __gcd(b, c);
    long ac = a * c / __gcd(a, c);
    long abc = a * bc / __gcd(a, bc);

    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      int cnt = mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac +
                mid / abc;
      if (cnt < k) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    return lo;
  }
};
