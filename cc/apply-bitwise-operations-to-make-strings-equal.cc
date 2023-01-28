// https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/
#include "xxx.hpp"

class Solution {
public:
  bool makeStringsEqual(string s, string target) {
    map<int, int> cnt1;
    map<int, int> cnt2;
    // 1 0 -> 1 1
    // 1 1 -> 1 0
    // 0 0 -> 0 0
    // 0 1 -> 1 1
    // we must have 1
    // count 1 and 0
    for (auto &c : s) {
      cnt1[c - '0']++;
    }
    for (auto &c : target) {
      cnt2[c - '0']++;
    }

    return (cnt1[1] > 0) == (cnt2[1] > 0);
  }
};
