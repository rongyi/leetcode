// https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/
#include "xxx.h"

class Solution {
public:
  bool isPrefixString(string s, vector<string> &words) {
    int start = 0;
    // compose one by one till we get a total s, if not
    // s is not a prefix of words
    for (auto &w : words) {
      int sz = w.size();
      if (s.substr(start, w.size()) != w) {
        return false;
      }
      start += sz;
      if (start == s.size()) {
        return true;
      }
    }
    // not long enough
    return false;
  }
};
