// https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/
#include "xxx.hpp"

class Solution {
public:
  // shitty problem
  int makeTheIntegerZero(int num1, int num2) {
    // With cnt operations, num1 should equal: num1 == cnt * num2 + diff.

    // diff is the sum of cnt single-bit numbers; a single-bit number is 2 power
    // something.

    // So, we check if we can make diff:

    // 1. Number of bits in diff should not exceed cnt.
    // 2. The minimum possible sum(which we call diff) is cnt * (2 ^ 0), so cnt
    // should not be larger than diff.
    for (int cnt = 1; cnt < 35 && num1 > 0; ++cnt) {
      num1 -= num2;
      // num1 is now the delta, which is diff value
      if (__builtin_popcountll(num1) <= cnt && cnt <= num1) {
        return cnt;
      }
    }

    return -1;
  }
};
