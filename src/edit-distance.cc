// http://leetcode.com/problems/edit-distance/description/
#include "one.h"

class Solution {
public:
  // https://www.youtube.com/watch?v=We3YDTzNXEk
  int minDistance(string word1, string word2) {
    if (word1.empty()) {
      return word2.length();
    }
    if (word2.empty()) {
      return word1.length();
    }
    const int m = word1.size();
    const int n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // 什么意思？就是把Word1变成空字符串的成本
    // 初始值如下：

    // ━━━━━━━━━━━━━━━━━━━━━━━
    //      ""  a  b  c  d  e
    // ───────────────────────
    //  ""   0  1  2  3  4  5
    //  a    1
    //  b    2
    //  c    3
    //  d    4
    //  e    5
    // ━━━━━━━━━━━━━━━━━━━━━━━
    for (int i = 0; i <= m; ++i) {
      dp[i][0] = i;
    }

    // 同上
    for (int j = 0; j <= n; ++j) {
      dp[0][j] = j;
    }

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
        }
      }
    }

    return dp[m][n];
  }
};
