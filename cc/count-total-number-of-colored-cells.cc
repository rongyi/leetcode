// https://leetcode.com/problems/count-total-number-of-colored-cells/
#include "xxx.hpp"

class Solution {
public:
  long long coloredCells(int n) {
    if (n == 1) {
      return 1;
    }
    long long t = n - 1;
    return 1 + (t + 1) * t * 2; // (1 + n) * n / 2 * 4
  }
};
