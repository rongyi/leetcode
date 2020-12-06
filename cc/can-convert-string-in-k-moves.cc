// http://leetcode.com/problems/can-convert-string-in-k-moves/description/
#include "xxx.h"

class Solution {
public:
  bool canConvertString(string s, string t, int k) {
    if (s.size() != t.size()) {
      return false;
    }

    int pow[26] = {};
    for (int i = 0; i < s.size(); ++i) {
      int shift = t[i] - s[i] + (t[i] < s[i] ? 26 : 0);
      if (shift != 0 && shift + 26 * pow[shift] > k) {
        return false;
      }
      ++pow[shift];
    }

    return true;
  }
};
