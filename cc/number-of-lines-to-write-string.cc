// https://leetcode.com/problems/number-of-lines-to-write-string/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> numberOfLines(vector<int> &widths, string s) {
    int line = 1;
    int line_chars = 0;
    for (int i = 0; i < s.size(); i++) {
      auto w = widths[s[i] - 'a'];
      line_chars += w;
      if (line_chars > 100) {
        line++;
        line_chars = 0;
        i--;
      }
    }
    return vector<int>{line, line_chars};
  }
};
