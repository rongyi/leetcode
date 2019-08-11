// http://leetcode.com/problems/camelcase-matching/description/
#include "xxx.h"

class Solution {
public:
  vector<bool> camelMatch(vector<string> &qs, string pattern) {
    vector<bool> ret;

    for (int i = 0; i < qs.size(); i++) {
      auto &curq = qs[i];
      // 比较的方式就是逐个比较，遇到大写的不等就赶紧闪
      int j = 0;
      int p = 0;
      for (; j < curq.size(); j++) {
        if (p < pattern.size() && pattern[p] == curq[j]) {
          p++;
        } else if (isupper(curq[j])) {
          break;
        }
      } // inner for end
      ret.push_back(j == curq.size() && p == pattern.size());
    } // outer for
    return ret;
  }
};
