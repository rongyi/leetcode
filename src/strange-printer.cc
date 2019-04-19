// http://leetcode.com/problems/strange-printer/description/
#include "xxx.h"

class Solution {
public:
  int strangePrinter(string s) {
    if (s.empty()) {
      return 0;
    }
    int uniq = 1;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] != s[uniq - 1]) {
        s[uniq++] = s[i];
      }
    }
    s.resize(uniq);

    const int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i; j < n; j++) {
        dp[i][j] = (i == j) ? 1 : dp[i + 1][j] + 1;
        for (int k = i + 1; k <= j; k++) {
          if (s[k] == s[i]) {
            dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
          }
        }
      }
    }
    return dp[0][n - 1];
  }
};
