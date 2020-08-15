// http://www.lintcode.com/zh-cn/problem/swap-adjacent-in-lr-string

#include "xxx.h"

class Solution {
public:
  bool canTransform(string start, string end) {
    const int n = start.size();
    int i = 0;
    int j = 0;
    while (i < n && j < n) {
      while (start[i] == 'X') {
        ++i;
      }
      while (end[j] == 'X') {
        ++j;
      }
      if (start[i] != end[j]) {
        return false;
      }
      // XL ==> LX 所以L的index在变小
      if (start[i] == 'L' && i < j) {
        return false;
      }
      // RX ==> XR 同样的，R的index在变大
      if (start[i] == 'R' && i > j) {
        return false;
      }
      ++i;
      ++j;
    }
    return true;
  }
};
