// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
#include "xxx.hpp"

class Solution {
public:
  string firstPalindrome(vector<string> &words) {
    auto predfn = [](string &s) -> bool {
      int i = 0;
      int j = s.size() - 1;
      while (i < j) {
        if (s[i] != s[j]) {
          return false;
        }
        i++;
        j--;
      }
      return true;
    };
    for (auto &s: words) {
      if (predfn(s)) {
        return s;
      }
    }
    return "";
  }
};
