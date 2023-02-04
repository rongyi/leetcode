// http://leetcode.com/problems/leetcode/roman-to-integer/description/
#include "xxx.hpp"

class Solution {
public:
  /**
   * @param s Roman representation
   * @return an integer
   */
  int romanToInt(string &s) {
    auto rtoi = [](const char c) -> int {
      switch (c) {
      case 'I':
        return 1;
      case 'V':
        return 5;
      case 'X':
        return 10;
      case 'L':
        return 50;
      case 'C':
        return 100;
      case 'D':
        return 500;
      case 'M':
        return 1000;
      default:
        return 0;
      }
    };
    int ret = 0;
    int sz = s.size();

    for (int i = 0; i < sz; i++) {
      switch (s[i]) {
      case 'I':
        if (i + 1 < sz && s[i + 1] == 'V') {
          ret += 4;
          i++;
        } else if (i + 1 < sz && s[i + 1] == 'X') {
          ret += 9;
          i++;
        } else {
          ret += rtoi(s[i]);
        }
        break;
      case 'X':
        if (i + 1 < sz && s[i + 1] == 'L') {
          ret += 40;
          i++;
        } else if (i + 1 < sz && s[i + 1] == 'C') {
          ret += 90;
          i++;
        } else {
          ret += rtoi(s[i]);
        }
        break;
      case 'C':
        if (i + 1 < sz && s[i + 1] == 'D') {
          ret += 400;
          i++;
        } else if (i + 1 < sz && s[i + 1] == 'M') {
          ret += 900;
          i++;
        } else {
          ret += rtoi(s[i]);
        }
        break;
      default:
        ret += rtoi(s[i]);
      }
    }

    return ret;
  }
};
