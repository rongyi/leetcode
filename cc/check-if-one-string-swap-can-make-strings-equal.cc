// http://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/
#include "xxx.hpp"

class Solution {
public:
  bool areAlmostEqual(string s1, string s2) {
    if (s1 == s2) {
      return true;
    }
    int diff1 = -1;
    int diff2 = -1;
    for (int i = 0; i < s1.size(); ++i) {
      if (s1[i] != s2[i]) {
        if (diff1 == -1) {
          diff1 = i;
        } else {
          diff2 = i;
          swap(s1[diff1], s1[diff2]);
          return s1 == s2;
        }
      }
    }

    return false;
  }
};
