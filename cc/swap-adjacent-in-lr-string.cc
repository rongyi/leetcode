// http://www.lintcode.com/zh-cn/problem/swap-adjacent-in-lr-string

#include "xxx.hpp"

class Solution {
public:
  bool canTransform(string start, string end) {
    const int n = start.size();
    int i = 0;
    int j = 0;
    string clean_start;
    string clean_end;
    for (int i = 0; i < n; i++) {
      if (start[i] != 'X') {
        clean_start.push_back(start[i]);
      }
    }
    for (int i = 0; i < n; i++) {
      if (end[i] != 'X') {
        clean_end.push_back(end[i]);
      }
    }
    if (clean_start != clean_end) {
      return false;
    }

    while (i < n && j < n) {
      while (start[i] == 'X') {
        ++i;
      }
      while (end[j] == 'X') {
        ++j;
      }
      if (i == n && j == n) {
        return true;
      }
      if (i == n || j == n || start[i] != end[j]) {
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
