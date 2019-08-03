// http://leetcode.com/problems/check-if-word-is-valid-after-substitutions/description/
#include "xxx.h"

class Solution {
public:
  bool isValid(string S, bool has_replace = false) {
    if (S.empty()) {
      return has_replace;
    }
    auto exist = S.find("abc");
    if (exist == string::npos) {
      return false;
    }
    string concat = S.substr(0, exist) + S.substr(exist + 3);

    return isValid(concat, true);
  }
};
