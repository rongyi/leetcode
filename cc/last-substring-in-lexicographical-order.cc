// http://leetcode.com/problems/last-substring-in-lexicographical-order/description/
#include "xxx.hpp"

class Solution {
public:
  string lastSubstring(string s) {
    int i = 0;
    int sz = 0;
    const int n = s.size();
    for (int j = 1; j < n; ++j) {
      for (sz = 0; j + sz < n; ++sz) {
        if (s[i + sz] == s[j + sz]) {
          continue;
        }
        i = s[j + sz] > s[i + sz] ? j : i;
        break;
      }
      if (j + sz == n) {
        break;
      }
    }
    return s.substr(i);
  }
};
