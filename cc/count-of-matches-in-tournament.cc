// http://leetcode.com/problems/count-of-matches-in-tournament/description/
#include "xxx.h"

class Solution {
public:
  int numberOfMatches(int n) {
    int ret = 0;

    while (n != 1) {
      ret += n / 2;
      if (n & 1) {
        n = n / 2 + 1;
      } else {
        n /= 2;
      }
    }

    return ret;
  }
};
