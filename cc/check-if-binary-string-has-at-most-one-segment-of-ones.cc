// http://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/
#include "xxx.hpp"

class Solution {
public:
  // 题目描述太扯了
  bool checkOnesSegment(string s) {
    const int n = s.size();
    for (int i = 1; i < n; ++i) {
      if (s[i - 1] == '0' && s[i] == '1') {
        return false;
      }
    }
    return true;
  }
};
