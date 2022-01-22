// http://leetcode.com/problems/split-a-string-in-balanced-strings/description/
#include "xxx.hpp"

class Solution {
public:
  int balancedStringSplit(string s) {
    int count[2] = {};
    int ret = 0;
    for (auto &c : s) {
      if (c == 'L') {
        ++count[0];
      } else {
        ++count[1];
      }
      if (count[0] == count[1]) {
        ++ret;
        count[0] = 0;
        count[1] = 0;
      }
    }

    return ret;
  }
};
