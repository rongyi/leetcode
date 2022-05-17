// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/
#include "xxx.hpp"

class Solution {
public:
  string removeDigit(string s, char digit) {
    int sz = s.size();
    for (int i = 0; i < sz; ++i) {
      if (s[i] == digit) {
        if (i < sz - 1 && s[i] < s[i + 1]) {
          return s.substr(0, i) + s.substr(i + 1);
        }
      }
    }

    // search from right
    for (int i = sz - 1; i >= 0; --i) {
      if (s[i] == digit) {
        return s.substr(0, i) + s.substr(i + 1);
      }
    }
    // not found
    return s;
  }
};
