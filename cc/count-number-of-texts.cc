// https://leetcode.com/problems/count-number-of-texts/
#include "xxx.hpp"

class Solution {
public:
  int countTexts(string s) {
    int sz = s.size();
    vector<int> dp(sz + 1, 0);
    dp[0] = 1;
    int mod = 1e9 + 7;

    for (int i = 0; i < sz; ++i) {
      // this single press, just equal to previous number
      dp[i + 1] = dp[i] % mod;
      // oh, two same, then, this two can combine
      if (i - 1 >= 0 && s[i - 1] == s[i]) {
        dp[i + 1] = (dp[i + 1] + dp[i - 2 + 1]) % mod;
        // oh three same, then this tree can combine
        if (i - 2 >= 0 && s[i - 2] == s[i]) {
          dp[i + 1] = (dp[i + 1] + dp[i - 3 + 1]) % mod;
          // 
          if (i - 3 >= 0 && (s[i] == '7' || s[i] == '9') && s[i] == s[i - 3]) {
            dp[i + 1] = (dp[i + 1] + dp[i - 4 + 1]) % mod;
          }
        }
      }
    }

    return dp[sz];
  }
};
