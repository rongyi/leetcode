// https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/
#include "xxx.hpp"

class Solution {
public:
  int longestContinuousSubstring(string s) {
    int sz = s.size();
    int ret = 1;
    for (int i = 0; i < sz;) {
      int j = i + 1;
      for (; j < sz && s[j] == s[j - 1] + 1; ++j) {
        ;
      }
      ret = max(ret, j - i);
      i = j;
    }

    // bingo!
    return ret;
  }
};
