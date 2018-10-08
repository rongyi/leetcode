// http://leetcode.com/problems/reverse-string/description/
#include "one.h"

class Solution {
public:
  string reverseString(string s) {
    const int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
      swap(s[i], s[n - i - 1]);
    }
    return s;
  }
};
