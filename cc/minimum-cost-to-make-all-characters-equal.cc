// https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal/
#include "xxx.hpp"

class Solution {
public:
  long long minimumCost(string s) {
    long long ret = 0;
    int sz = s.size();
    for (int i = 1; i < sz; i++) {
      if (s[i] != s[i - 1]) {
        ret += min(i, sz - i);
      }
    }

    return ret;
  }
};
