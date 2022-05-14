// https://leetcode.com/problems/count-prefixes-of-a-given-string/
#include "xxx.hpp"

class Solution {
public:
  int countPrefixes(vector<string> &words, string s) {
    int sz = s.size();
    int ret = 0;
    for (auto &cur : words) {
      if (cur.size() > sz) {
        continue;
      }
      int checksz = min(sz, (int)cur.size());
      if (cur.substr(0, checksz) == s.substr(0, checksz)) {
        ++ret;
      }
    }

    return ret;
  }
};
