// https://leetcode.com/problems/count-pairs-of-similar-strings/
#include "xxx.hpp"

class Solution {
public:
  int similarPairs(vector<string> &words) {
    map<int, int> cnt;
    int ret = 0;
    for (auto &w : words) {
      int bit = 0;
      for (auto &c : w) {
        bit |= 1 << (c - 'a');
      }
      ret += cnt[bit]++;
    }

    return ret;
  }
};
