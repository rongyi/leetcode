// http://leetcode.com/problems/largest-odd-number-in-string/description/
#include "xxx.h"

class Solution {
public:
    string largestOddNumber(string num) {
      int sz = num.size();
      int i = sz - 1;
      for (; i >= 0; --i) {
        if ((num[i] - '0') & 1) {
          break;
        }
      }

      if (i < 0) {
        return "";
      }

      return num.substr(0, i + 1);
    }
};
