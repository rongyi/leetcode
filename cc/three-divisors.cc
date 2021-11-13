// https://leetcode.com/problems/three-divisors/
#include "xxx.h"

class Solution {
public:
  bool isThree(int n) {
    // must be a squire number
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        if (n / i != i) {
          return false;
        }
        return true;
      }
    }
    return false;
  }
};
