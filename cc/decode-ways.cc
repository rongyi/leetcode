// http://leetcode.com/problems/decode-ways/description/
#include "xxx.hpp"

class Solution {
public:
  int numDecodings(string s) {
    int sz = s.size();
    vector<int> dp(sz + 1, 0);
    // for accumulation
    dp[sz] = 1;
    for (int i = sz - 1; i >= 0; i--) {
      if (s[i] != '0') {
        dp[i] += dp[i + 1];
      }
      if (i < sz - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
        dp[i] += dp[i + 2];
      }
    }
    return dp[0];
  }
};
