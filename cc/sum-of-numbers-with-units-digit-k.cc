// https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/
#include "xxx.hpp"

class Solution {
public:
  // 100% fast shit!
  int minimumNumbers(int num, int k) {
    if (num == 0) {
      return 0;
    }
    if (num < k) {
      return -1;
    }
    int right_most = num % 10;
    bool found = false;
    int i = 1;
    for (; i <= 10; ++i) {
      if (((k * i) % 10) == right_most) {
        found = true;
        break;
      }
    }
    if (!found) {
      return -1;
    }
    if (num < (k * i)) {
      return -1;
    }

    return i;
  }
};
