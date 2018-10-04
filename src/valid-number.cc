// http://leetcode.com/problems/leetcode/valid-number/description/
#include "one.h"

class Solution {
public:
  // 这道题被喷的非常厉害，细节题，确实没什么含量
  bool isNumber(string s) {
    bool num = false, numAfterE = true, dot = false, exp = false, sign = false;

    const int n = s.size();

    for (int i = 0; i < n; i++) {
      if (s[i] == ' ') {
        if (i < n - 1 && s[i + 1] != ' ' && (num || dot || exp || sign))
          return false;
      } else if (s[i] == '+' || s[i] == '-') {
        if (i > 0 && s[i - 1] != 'e' && s[i - 1] != ' ')
          return false;
        sign = true;
      } else if (s[i] >= '0' && s[i] <= '9') {
        num = true;
        numAfterE = true;
      } else if (s[i] == '.') {
        if (dot || exp)
          return false;
        dot = true;
      } else if (s[i] == 'e') {
        if (exp || !num)
          return false;
        exp = true;
        numAfterE = false;
      } else {
        return false;
      }
    }
    return num && numAfterE;
  }
};
