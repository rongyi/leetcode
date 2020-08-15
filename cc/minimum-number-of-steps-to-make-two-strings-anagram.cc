// http://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/
#include "xxx.h"

class Solution {
public:
  int minSteps(string s, string t) {
    const int n = s.size();
    vector<int> cnta(26, 0);
    vector<int> cntb(26, 0);
    for (auto c : s) {
      cnta[c - 'a']++;
    }

    for (auto c : t) {
      cntb[c - 'a']++;
    }
    int ret = 0;
    for (int i = 0; i < 26; i++) {
      ret += abs(cnta[i] - cntb[i]);
    }
    return ret / 2;
  }
};
