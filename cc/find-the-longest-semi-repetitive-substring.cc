// https://leetcode.com/problems/find-the-longest-semi-repetitive-substring/
#include "xxx.hpp"

class Solution {
public:
  int longestSemiRepetitiveSubstring(string s) {
    int ret = 1;
    int i = 0;
    int j = 1;
    int last_pair = 0;
    while (j < s.size()) {
      if (s[j] == s[j - 1]) {
        if (last_pair) {
          i = last_pair;
        }
        last_pair = j;
      }
      ret = max(ret, j - i + 1);
      j++;
    }

    return ret;
  }
};
