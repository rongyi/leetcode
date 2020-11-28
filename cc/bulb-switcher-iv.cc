// http://leetcode.com/problems/bulb-switcher-iv/description/
#include "xxx.h"

class Solution {
public:
  int minFlips(string target) {
    int total = 0;
    int state = 0;
    for (auto c : target) {
      if (c - '0' != state) {
        state = c - '0';
        ++total;
      }
    }

    return total;
  }
};
