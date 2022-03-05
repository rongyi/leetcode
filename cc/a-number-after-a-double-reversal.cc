// https://leetcode.com/problems/a-number-after-a-double-reversal/
#include "xxx.hpp"

class Solution {
public:
  bool isSameAfterReversals(int num) {
    string s = to_string(num);
    int sz = s.size();

    if (sz <= 1) {
      return true;
    }

    return s[sz - 1] != '0';
  }
};
