// http://leetcode.com/problems/strong-password-checker/description/
#include "xxx.h"

class Solution {
public:
  int strongPasswordChecker(string s) {
    int required_char = getRequiredChar(s);
    if (s.size() < 6) {
      return max(required_char, int(6 - s.size()));
    }

    int replace = 0;
    int oned = 0;
    int twod = 0;

    for (int i = 0; i < s.size();) {
      int len = 1;
      while (i + len < s.size() && s[i + len] == s[i + len - 1]) {
        len++;
      }
      if (len >= 3) {
        replace += len / 3;
        if (len % 3 == 0) {
          oned += 1;
        }
        if (len % 3 == 1) {
          twod += 2;
        }
      }
      i += len;
    }
    if (s.size() <= 20) {
      return max(required_char, replace);
    }

    int delete_count = s.size() - 20;
    // deleting 1 char in (3n) repeated chars will save one replacement
    replace -= min(delete_count, oned);

    // deleting 2 chars in (3n+1) repeated chars will save one replacement
    replace -= min(max(delete_count - oned, 0), twod) / 2;

    // deleting 3 chars in (3n+2) repeated chars will save one replacement
    replace -= max(delete_count - oned - twod, 0) / 3;

    return delete_count + max(required_char, replace);
  }

public:
  int getRequiredChar(string &s) {
    int lower_case = 1;
    int upper_case = 1;
    int digit = 1;

    for (auto c : s) {
      if (islower(c)) {
        lower_case = 0;
      } else if (isupper(c)) {
        upper_case = 0;
      } else if (isdigit(c)) {
        digit = 0;
      }
    }
    return lower_case + upper_case + digit;
  }
};
