// https://leetcode.com/problems/mirror-reflection/description/

#include "xxx.h"
class Solution {
public:
  int mirrorReflection(int p, int q) {
    int k = 1;
    while (p * k % q != 0) {
      ++k;
    }
    if (k & 1) {
      auto d = p * k / q;
      if (d & 1) {
        return 1;
      }
      return 2;
    }
    return 0;
  }
};
