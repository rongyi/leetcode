// http://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/
#include "xxx.hpp"

class Solution {
public:
  int minPartitions(string n) {
    char ret = '0';
    for (auto &c : n) {
      ret = max(ret, c);
      // shortcut
      if (ret == '9') {
        return 9;
      }
    }
    return ret - '0';
  }
};
