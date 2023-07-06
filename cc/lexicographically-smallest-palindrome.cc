// https://leetcode.com/problems/lexicographically-smallest-palindrome/
#include "xxx.hpp"

class Solution {
public:
  string makeSmallestPalindrome(string s) {
    int sz = s.size();
    for (int i = 0, j = sz - 1; i < j; i++, j--) {
      if (s[i] != s[j]) {
        s[i] = s[j] = min(s[i], s[j]);
      }
    }

    return s;
  }
};
