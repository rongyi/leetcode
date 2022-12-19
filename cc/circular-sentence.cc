// https://leetcode.com/problems/circular-sentence/
#include "xxx.hpp"

class Solution {
public:
  bool isCircularSentence(string s) {
    int sz = s.size();

    for (int i = 0; i < sz; ++i) {
      if (s[i] == ' ') {
        if (s[i - 1] != s[i + 1]) {
          return false;
        }
      }
    }

    return s[0] == s[sz - 1];
  }
};
