// http://leetcode.com/problems/valid-palindrome/description/
#include "xxx.hpp"

class Solution {
public:
  bool isPalindrome(string s) {
    int sz = s.size();
    int i = 0;
    int j = sz - 1;
    while (i < j) {
      if (!isalnum(s[i])) {
        i++;
        continue;
      }
      if (!isalnum(s[j])) {
        j--;
        continue;
      }
      if (tolower(s[i]) != tolower(s[j])) {
        return false;
      }
      i++;
      j--;
    }

    return true;
  }
};
