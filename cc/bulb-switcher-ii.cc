// http://leetcode.com/problems/bulb-switcher-ii/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/bulb-switcher-ii/discuss/107278/Very-easy-to-understand-C%2B%2B-with-detailed-explanation
  int flipLights(int n, int m) {
    if (m == 0) {
      // only the initial status: all on
      return 1;
    }
    if (n == 1) {
      if (m >= 1) {
        return 2;
      }
    }
    if (n == 2) {
      if (m == 1) {
        return 3;
      }
      if (m >= 2) {
        return 4;
      }
    }
    if (n >= 3) {
      if (m == 1) {
        return 4;
      }
      if (m == 2) {
        return 7;
      }
      if (m >= 3) {
        return 8;
      }
    }

    return 0;
  }
};
