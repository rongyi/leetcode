// http://leetcode.com/problems/reach-a-number/description/
#include "xxx.h"

class Solution {
public:
  int reachNumber(int target) {
    target = abs(target);
    int i = sqrt(2 * target);
    while (true) {
      int remain = i * i + i - 2 * target;
      if (remain >= 0 && remain % 4 == 0) {
        return i;
      }
      ++i;
    }
  }
};
