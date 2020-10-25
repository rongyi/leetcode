// http://leetcode.com/problems/xor-operation-in-an-array/description/
#include "xxx.h"

class Solution {
public:
  int xorOperation(int n, int start) {
    int ret = start;
    for (int i = 1; i < n; ++i) {
      ret ^= (start + 2 * i);
    }

    return ret;
  }
};
