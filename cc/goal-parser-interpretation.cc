// http://leetcode.com/problems/goal-parser-interpretation/description/
#include "xxx.h"

class Solution {
public:
  string interpret(string s) {
    const int n = s.size();
    ostringstream ss;
    int i = 0;
    while (i < n) {
      if (s[i] == '(') {
        // peek next, they promise i + 1 will in boundary
        if (s[i + 1] == ')') {
          ss << 'o';
          i += 2;
        } else {
          // must be(al)
          ss << "al";
          i += 4;
        }
      } else {
        ss << 'G';
        i++;
      }
    }

    return ss.str();
  }
};
