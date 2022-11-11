// https://leetcode.com/problems/number-of-common-factors/
#include "xxx.hpp"

class Solution {
public:
  int commonFactors(int a, int b) {
    int cnt = 1;
    for (int i = 2; i <= min(a, b); ++i) {
      if (a % i == 0 && b % i == 0) {
        ++cnt;
      }
    }
    return cnt;
  }
};
