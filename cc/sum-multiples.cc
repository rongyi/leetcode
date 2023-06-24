// https://leetcode.com/problems/sum-multiples/
#include "xxx.hpp"

class Solution {
public:
  int sumOfMultiples(int n) {
    int ret = 0;
    for (int i = 3; i <= n; i++) {
      if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
        ret += i;
      }
    }
    return ret;
  }
};
