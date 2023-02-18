// http://leetcode.com/problems/length-of-last-word/description/
#include "xxx.hpp"

class Solution {
public:
  int lengthOfLastWord(string s) {
    int sz = s.size();
    int j = sz - 1;
    for (; j >= 0 && s[j] == ' '; --j) {
    }
    if (j == -1) {
      return 0;
    }
    int last_space = -1;
    for (int i = 0; i < j; i++) {
      if (s[i] == ' ') {
        last_space = i;
      }
    }
    return j - last_space;
  }
};

