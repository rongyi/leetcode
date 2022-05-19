// https://leetcode.com/problems/largest-3-same-digit-number-in-string/
#include "xxx.hpp"

class Solution {
public:
  string largestGoodInteger(string num) {
    int sz = num.size();
    // use integer 0 as initial value, special for c++
    char cur = 0;
    for (int i = 0; i < sz - 2; ++i) {
      if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
        cur = max(cur, num[i]);
      }
    }
    if (cur == 0) {
      return "";
    }

    return string(3, cur);
  }
};
