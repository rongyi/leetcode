// http://leetcode.com/problems/remove-palindromic-subsequences/description/
#include "xxx.hpp"

class Solution {
public:
  // 喷的特别惨
  int removePalindromeSub(string s) {
    if (s.empty()) {
      return 0;
    }
    if (s == string(s.rbegin(), s.rend())) {
      return 1;
    }
    // string containes only two letters 'a' and 'b'
    // we can first remote 'a' and then remote 'b'
    // to let the string empty
    return 2;
  }
};
