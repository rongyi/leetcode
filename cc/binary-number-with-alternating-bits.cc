// http://leetcode.com/problems/binary-number-with-alternating-bits/description/
#include "xxx.h"

class Solution {
public:
  bool hasAlternatingBits(int n) {
    int prev = -1;
    while (n) {
      if (prev == -1) {
        prev = (n & 1);
        n >>= 1;
        continue;
      }
      int cur = (n & 1);
      if (cur == prev) {
        return false;
      }
      prev = cur;
      n >>= 1;
    }
    return true;
  }
};
