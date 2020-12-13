// http://leetcode.com/problems/minimum-operations-to-make-array-equal/description/
#include "xxx.h"

class Solution {
public:
  int minOperations(int n) {
    // just math
    if (n & 1) {
      if (n == 1) {
        return 0;
      }
      const int count = n / 2;
      // return count * (2 + count * 2) / 2;
      return count * (count + 1);
    }
    // even case
    const int count = n / 2;

    return count * count;
  }
};
