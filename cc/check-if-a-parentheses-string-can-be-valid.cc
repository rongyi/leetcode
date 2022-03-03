// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/
#include "xxx.hpp"

class Solution {
public:
  bool canBeValid(string s, string locked) {
    int sz = s.size();
    if (sz & 1) {
      return false;
    }
    int balance = 0;
    for (int i = 0; i < sz; ++i) {
      if (s[i] == '(' || locked[i] == '0') {
        balance++;
      } else {
        balance--;
      }
      if (balance < 0) {
        return false;
      }
    }
    balance = 0;
    for (int i = sz - 1; i >= 0; --i) {
      if (s[i] == ')' || locked[i] == '0') {
        balance++;
      } else {
        balance--;
      }

      if (balance < 0) {
        return false;
      }
    }
    return true;
  }
};
