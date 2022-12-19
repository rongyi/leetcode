// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/
#include "xxx.hpp"

class Solution {
public:
  int appendCharacters(string s, string t) {
    int sz1 = s.size();
    int sz2 = t.size();
    int j = 0;
    for (int i = 0; i < sz1 && j < sz2; ++i) {
      if (s[i] == t[j]) {
        j++;
      }
    }

    return sz2 - j;
  }
};
