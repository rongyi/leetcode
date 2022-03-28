// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/
#include "xxx.hpp"

class Solution {
public:
  int minSteps(string s, string t) {
    // just summary the diff
    vector<int> cnt1(26, 0);
    vector<int> cnt2(26, 0);
    for (auto c : s) {
      cnt1[c - 'a']++;
    }
    for (auto c : t) {
      cnt2[c - 'a']++;
    }
    int ret = 0;
    for (int i = 0; i < 26; ++i) {
      ret += abs(cnt1[i] - cnt2[i]);
    }
    return ret;
  }
};
