// http://leetcode.com/problems/bulb-switcher/description/
#include "xxx.h"

class Solution {
public:
  int bulbSwitch(int n) {
    int ret = 0;
    for (int i = 1; i * i <= n; i++) {
      ++ret;
    }
    return ret;
  }
};
