// http://leetcode.com/problems/palindromic-substrings/description/
#include "xxx.hpp"

class Solution {
public:
  int countSubstrings(string s) {
    const int n = s.size();
    int ret = 0;
    for (int i = 0; i < n; i++) {
      // 以i为中心
      for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++) {
        ret++;
      }
      // 以 (i - 1), i为中心
      for (int j = 0;
           (i - 1 - j) >= 0 && (i + j) < n && s[i - 1 - j] == s[i + j]; j++) {
        ret++;
      }
    }

    return ret;
  }
};
