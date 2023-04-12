// http://leetcode.com/problems/excel-sheet-column-number/description/
#include "xxx.hpp"

class Solution {
public:
  int titleToNumber(string s) {
    int ret = 0;
    for (auto &c : s) {
      ret = ret * 26 + (c - 'A') + 1;
    }

    return ret;
  }
};
