// https://leetcode.com/problems/find-the-punishment-number-of-an-integer/
#include "xxx.hpp"

class Solution {
public:
  int punishmentNumber(int n) {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
      int sqr = i * i;
      if (check(to_string(sqr), 0, i)) {
        ret += sqr;
      }
    }
    return ret;
  }

private:
  int check(string s, int cur, int num) {
    if (cur == s.size() && num == 0) {
      return true;
    }
    if (num < 0) {
      return false;
    }
    int acc = 0;
    for (int i = cur; i < s.size(); i++) {
      acc = acc * 10 + (s[i] - '0');
      if (check(s, i + 1, num - acc)) {
        return true;
      }
    }

    return false;
  }
};
