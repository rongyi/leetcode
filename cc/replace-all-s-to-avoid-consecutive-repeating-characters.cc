// http://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/description/
#include "xxx.hpp"

class Solution {
public:
  string modifyString(string s) {
    char c = 'a';
    const int n = s.size();
    auto validchar = [&](int i) -> char {
      for (; (i + 1 < n && c == s[i + 1]) || (i - 1 >= 0 && c == s[i - 1]);
           c = (c - 'a' + 1) % 26 + 'a')
        ;
      return c;
    };
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '?') {
        s[i] = validchar(i);
      }
    }

    return s;
  }
};
