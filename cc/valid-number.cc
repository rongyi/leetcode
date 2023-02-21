// http://leetcode.com/problems/leetcode/valid-number/description/
#include "xxx.hpp"

class Solution {
public:
  bool isNumber(string s) {
    int sz = s.size();
    int i = 0;
    while (i < sz && s[i] == ' ') {
      i++;
    }
    if (i == sz) {
      return false;
    }
    if (s[i] == '+' || s[i] == '-') {
      i++;
    }
    int dotcnt = 0;
    int digcnt = 0;
    for (; i < sz && (s[i] == '.' || (s[i] <= '9' && s[i] >= '0')); i++) {
      if (s[i] == '.') {
        dotcnt++;
      } else {
        digcnt++;
      }
    }
    if (dotcnt > 1 || digcnt < 1) {
      return false;
    }
    // option e
    if (s[i] == 'e' || s[i] == 'E') {
      i++;

      if (s[i] == '+' || s[i] == '-') {
        i++;
      }
      digcnt = 0;
      for (; i < sz && (s[i] <= '9' && s[i] >= '0'); i++) {
        digcnt++;
      }
      if (digcnt == 0) {
        return false;
      }
    }
    for (; i < sz && s[i] == ' '; i++) {
    }

    return i == sz;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  so.isNumber("1E9");
  return 0;
}
