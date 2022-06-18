// https://leetcode.com/problems/strong-password-checker-ii/
#include "xxx.hpp"

class Solution {
public:
  bool strongPasswordCheckerII(string s) {
    if (s.size() < 8) {
      return false;
    }
    const string special{"!@#$%^&*()-+"};
    bool have_lower = islower(s[0]);
    bool have_upper = isupper(s[0]);
    bool have_digit = isdigit(s[0]);
    bool have_special = special.find(s[0]) != string::npos;
    for (int i = 1; i < s.size(); ++i) {
      // can not contain 2 same in adjacent positions
      if (s[i] == s[i - 1]) {
        return false;
      }
      have_lower |= islower(s[i]);
      have_upper |= isupper(s[i]);
      have_digit |= isdigit(s[i]);
      have_special |= special.find(s[i]) != string::npos;
    }
    if (!have_lower || !have_upper || !have_digit || !have_special) {
      return false;
    }

    return true;
  }
};
