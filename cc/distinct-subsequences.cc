// http://leetcode.com/problems/distinct-subsequences/description/
#include "xxx.hpp"

class Solution {
public:
  int numDistinct(string s, string t) {
    // dp[i][j]
    // target t[i - 1]
    // source: s[j - 1]
    // t[i - 1] == s[j - 1] --> dp[i][j - 1] + dp[i - 1][j - 1]
    // t[i - 1] != s[j - 1] -> dp[i][j - 1]
    //
    // dp[0][j] = 1
    int m = t.size();
    int n = s.size();
    vector<vector<unsigned long long>> dp(
        m + 1, vector<unsigned long long>(n + 1, 0ull));

    for (int j = 0; j <= n; j++) {
      dp[0][j] = 1;
    }

    for (int j = 1; j <= n; j++) {
      for (int i = 1; i <= m; i++) {
        if (t[i - 1] == s[j - 1]) {
          dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
    return dp[m][n];
  }
};
