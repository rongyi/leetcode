// https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
#include "xxx.hpp"

class Solution {
public:
  bool checkString(string s) {
    bool meetb = false;
    for (auto c: s) {
      if (c == 'b') {
        meetb = true;
      }

      if (c == 'a' && meetb) {
        return false;
      }
    }
    return true;
  }
};
