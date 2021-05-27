// http://leetcode.com/problems/count-the-number-of-consistent-strings/description/
#include "xxx.h"

class Solution {
public:
  int countConsistentStrings(string allowed, vector<string> &words) {
    vector<int> count(26, 0);
    for (auto &c : allowed) {
      count[c - 'a']++;
    }
    int ret = 0;
    for (auto &w : words) {
      bool valid = true;
      for (auto &c : w) {
        // 出现了不该出现的字符，这个string就不是了
        if (count[c - 'a'] == 0) {
          valid = false;
          break;
        }
      }
      if (valid) {
        ++ret;
      }
    }

    return ret;
  }
};
