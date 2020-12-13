// http://leetcode.com/problems/thousand-separator/description/
#include "xxx.h"

class Solution {
public:
  string thousandSeparator(int n) {
    auto s = to_string(n);

    string ret;
    for (int i = s.size() - 1, t = 0; i >= 0; --i) {
      ++t;
      ret.push_back(s[i]);
      if (t > 0 && t % 3 == 0) {
        ret.push_back('.');
      }
    }
    if (ret.back() == '.') {
      ret.pop_back();
    }
    reverse(ret.begin(), ret.end());

    return ret;
  }
};
