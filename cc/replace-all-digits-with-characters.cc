// http://leetcode.com/problems/replace-all-digits-with-characters/description/
#include "xxx.h"

class Solution {
public:
  string replaceDigits(string s) {
    string ret;
    for (int i = 0; i < s.size(); ++i) {
      if (i & 1) {
        ret.push_back(s[i - 1] + (s[i] - '0'));
      } else {
        ret.push_back(s[i]);
      }
    }
    return ret;
  }
};
