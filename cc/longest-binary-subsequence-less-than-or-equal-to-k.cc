// https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/
#include "xxx.hpp"

class Solution {
public:
  int longestSubsequence(string s, int k) {
    int zerocount = count(s.begin(), s.end(), '0');
    int val = 0;
    int pow = 1;
    int onecount = 0;

    for (int i = s.size() - 1; i >= 0 && (val + pow) <= k; i--) {
      if (s[i] == '1') {
        val += pow;
        onecount += 1;
      }
      pow <<= 1;
    }

    return zerocount + onecount;
  }
};
