// https://leetcode.com/problems/delete-characters-to-make-fancy-string/
#include "xxx.h"

class Solution {
public:
  string makeFancyString(string s) {
    // current ch can be inserted to ret
    // when there are no two same char before it
    string ret{"  "};

    for (int i = 0; i < s.size(); ++i) {
      char cur = s[i];
      char prev = ret.back();
      char pprev = ret[ret.size() - 2];
      if ((cur == prev) && (cur == pprev)) {
        continue;
      }
      ret.push_back(cur);
    }

    return ret.substr(2);
  }
};
