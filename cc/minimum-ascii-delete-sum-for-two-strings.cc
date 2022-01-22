// http://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
#include "xxx.hpp"

class Solution {
public:
  // dp[i][j] is the cost for s1.substr(0,i) and s2.substr(0, j). Note s1[i],
  // s2[j] not included in the substring.

  // Base case: dp[0][0] = 0
  // target: dp[m][n]

  // if s1[i-1] = s2[j-1]   // no deletion
  //     dp[i][j] = dp[i-1][j-1];
  // else   // delete either s1[i-1] or s2[j-1]
  //     dp[i][j] = min(dp[i-1][j]+s1[i-1], dp[i][j-1]+s2[j-1]);
  int minimumDeleteSum(string s1, string s2) {
    const int m = s1.size();
    const int n = s2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // first row
    for (int j = 1; j <= n; j++) {
      // 把s2删到空字符串和s1相等，就是全加起来
      dp[0][j] = dp[0][j - 1] + s2[j - 1];
    }

    for (int i = 1; i <= m; i++) {
      // 一样，删空的全部和
      dp[i][0] = dp[i - 1][0] + s1[i - 1];
      for (int j = 1; j <= n; j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          // delete s1[i - 1] or s2[j - 1]
          dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
        }
      }
    }
    return dp[m][n];
  }
};
