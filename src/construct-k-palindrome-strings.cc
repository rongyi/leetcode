// http://leetcode.com/problems/construct-k-palindrome-strings/description/
#include "xxx.h"

class Solution {
public:
  bool canConstruct(string s, int k) {
    if (k > s.size()) {
      return false;
    }

    unordered_map<char, int> count;
    for (auto &c : s) {
      ++count[c];
    }
    int odd_count = 0;
    int even_pair = 0;
    for (auto &kv : count) {
      if (kv.second & 1) {
        ++odd_count;
      }
      even_pair += kv.second / 2;
    }
    // 奇数的那些个是要独立成一组的
    if (k < odd_count) {
      return false;
    }
    auto left = k - odd_count;

    return (left >= 0) && (left <= even_pair * 2);
  }
};
