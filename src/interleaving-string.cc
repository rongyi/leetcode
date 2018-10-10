// http://leetcode.com/problems/leetcode/interleaving-string/description/
#include "one.h"

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.empty() && s2.empty() && s3.empty()) {
      return true;
    }
    if (s1.empty()) {
      return s2 == s3;
    }
    if (s2.empty()) {
      return s1 == s3;
    }
    int m = s1.size();
    int n = s2.size();
    int q = s3.size();
    if (m + n != q) {
      return false;
    }

    // 设状态f[i][j]，表示s1[0,i]和s2[0,j]，匹配s3[0,
    // i+j]。如果s1的最后一个字符等于s3的最后一个字符，则f[i][j]=f[i-1][j]；
    // 如果s2的最后一个字符等于s3的最后一个字符，则f[i][j]=f[i][j-1]
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= m; ++i) {
      dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
    }
    for (int j = 1; j <= n; ++j) {
      dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
    }
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                   (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
      }
    }
    return dp[m][n];
  }
};
