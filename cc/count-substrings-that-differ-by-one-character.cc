// http://leetcode.com/problems/count-substrings-that-differ-by-one-character/description/
#include "xxx.hpp"

class Solution {
public:
  int countSubstrings(string s, string t) {
    int ret = 0;
    const int m = s.size();
    const int n = t.size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int diff = 0;
        for (int k = 0; i + k < m && j + k < n; ++k) {
          if (s[i + k] != t[j + k]) {
            diff++;
          }
          if (diff > 1) {
            break;
          }
          // diff == 0 -> +0
          // diff == 1 -> +1
          ret += diff;
        }
      }
    }

    return ret;
  }
};
