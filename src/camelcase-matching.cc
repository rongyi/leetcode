// http://leetcode.com/problems/camelcase-matching/description/
#include "xxx.h"

class Solution {
public:
  vector<bool> camelMatch(vector<string> &qs, string pattern) {
    vector<bool> ret;
    for (int i = 0; i < qs.size(); i++) {
      auto &curq = qs[i];
      int p = 0;
      int j = 0;
      for (; j < curq.size(); ++j) {
        if (p < pattern.size() && curq[j] == pattern[p]) {
          ++p;
        } else if (!islower(curq[j])) {
          break;
        }
      }
      ret.push_back(j == curq.size() && p == pattern.size());
    }
    return ret;
  }
};
