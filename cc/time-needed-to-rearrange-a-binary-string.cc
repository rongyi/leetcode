// https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/
#include "xxx.hpp"

class Solution {
public:
  int secondsToRemoveOccurrences(string s) {
    round_ = 0;
    sz_ = s.size();
    check(s);

    return round_;
  }

private:
  void check(string &s) {
    bool has_change = false;
    for (int i = 0; i < sz_ - 1;) {
      if (s[i] == '0' && s[i + 1] == '1') {
        swap(s[i], s[i + 1]);
        i += 2;
        has_change = true;
      } else {
        i++;
      }
    }
    if (has_change) {
      ++round_;
      check(s);
    }
  }

private:
  int round_;
  int sz_;
};
