// https://leetcode.com/problems/count-asterisks/
#include "xxx.hpp"

class Solution {
public:
  int countAsterisks(string s) {
    int sz = s.size();
    int bar_idx = 0;
    int ret = 0;
    for (int i = 0; i < sz; ++i) {
      if (s[i] == '|') {
        bar_idx++;
      }
      if (s[i] == '*') {
        ret += (bar_idx % 2) == 0;
      }
    }

    return ret;
  }
};
