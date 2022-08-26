// https://leetcode.com/problems/first-letter-to-appear-twice/
#include "xxx.hpp"

class Solution {
public:
  char repeatedCharacter(string s) {
    vector<int> cnt(26, 0);
    for (auto c: s) {
      cnt[c - 'a']++;
      if (cnt[c - 'a'] == 2) {
        return c;
      }
    }

    return '0';
  }
};
