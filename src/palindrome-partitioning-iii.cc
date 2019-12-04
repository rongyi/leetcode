// http://leetcode.com/problems/palindrome-partitioning-iii/description/
#include "xxx.h"

class Solution {
public:
  // 分成k份的最小change，让每一份都变成回文
  int palindromePartition(string s, int K) {
    const int n = s.size();
    if (K == 0 || n == 0) {
      return 0;
    }
    // 最少的change让 change[i][j] 子字符串变成回文
    vector<vector<int>> change(n, vector<int>(n, 0));
    for (int len = 1; len <= n; ++len) {
      for (int i = 0; i <= n - len; ++i) {
        int j = i + len - 1;
        if (i == j) {
          change[i][j] = 0;
        } else if (i == j - 1) {
          change[i][j] = s[i] == s[j] ? 0 : 1;
        } else {
          change[i][j] =
              s[i] == s[j] ? change[i + 1][j - 1] : change[i + 1][j - 1] + 1;
        }
      }
    }
    vector<vector<int>> dp(K + 1, vector<int>(n, numeric_limits<int>::max()));

    for (int i = 0; i < n; ++i) {
      // 分成一份的值就是从0 ==> i的子字符创需要改变的值
      dp[1][i] = change[0][i];
    }

    for (int k = 2; k <= K; ++k) {
      for (int i = k - 1; i < n; ++i) {
        for (int j = i - 1; j >= k - 2; --j) {
          dp[k][i] = min(dp[k][i], change[j + 1][i] + dp[k - 1][j]);
        }
      }
    }
    return dp[K][n - 1];
  }
};
