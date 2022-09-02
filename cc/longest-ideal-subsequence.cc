// https://leetcode.com/problems/longest-ideal-subsequence/
#include "xxx.hpp"

class Solution {
public:
  int longestIdealString(string s, int k) {
    int ret = 0;
    vector<int> dp(150, 0);
    for (auto &c: s) {
      // prev char
      for (int pc = c - k; pc <= c + k; ++pc) {
        dp[c] = max(dp[c], dp[pc]);
      }
      ret = max(ret, ++dp[c]);
    }

    return ret;
  }
};
