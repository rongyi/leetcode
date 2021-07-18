// http://leetcode.com/problems/maximize-palindrome-length-from-subsequences/description/
#include "xxx.h"

class Solution {
public:
  int longestPalindrome(string word1, string word2) {
    const int m = word1.size();
    const int n = word2.size();
    auto s = word1 + word2;
    vector<vector<int>> dp(m + n, vector<int>(m + n, 0));
    preCal(s, dp);
    int ret = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (word1[i] != word2[j]) {
          continue;
        }
        ret = max(ret, 2 + dp[i + 1][m + j - 1]);
      }
    }
    return ret;
  }

private:
  // 拼接起来的memo
  void preCal(string &s, vector<vector<int>> &dp) {
    const int n = s.size();

    for (int i = n - 1; i >= 0; i--) {
      for (int j = i + 1; j < n; ++j) {
        dp[i][i] = 1;
        if (s[i] == s[j]) {
          dp[i][j] = 2 + dp[i + 1][j - 1];
        } else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }
  }
};
