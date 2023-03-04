// http://leetcode.com/problems/leetcode/interleaving-string/description/
#include "xxx.hpp"

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size();
    int n = s2.size();
    if (s3.size() != (m + n)) {
      return false;
    }
    // dp_ = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
    // dp[i][j] --> s1 len is i and s2 len is j
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][0] = true;
    for (int j = 1; j <= n; j++) {
      if (s2[j - 1] == s3[j - 1]) {
        dp[0][j] = true;
      } else {
        break;
      }
    }
    for (int i = 1; i <= m; i++) {
      if (s1[i - 1] == s3[i - 1]) {
        dp[i][0] = true;
      } else {
        break;
      }
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (s1[i - 1] == s3[i + j - 1]) {
          dp[i][j] |= dp[i - 1][j];
        }
        if (s2[j - 1] == s3[i + j - 1]) {
          dp[i][j] |= dp[i][j - 1];
        }
      }
    }

    return dp[m][n];
  }

private:
  bool recur(string &s1, int i, string &s2, int j, string &s3) {
    if (i == s1.size() && j == s2.size()) {
      return true;
    }
    if (dp_[i][j] != -1) {
      return dp_[i][j];
    }
    if (i < s1.size() && s1[i] == s3[i + j]) {
      bool check = recur(s1, i + 1, s2, j, s3);
      if (check) {
        return true;
      }
    }
    if (j < s2.size() && s2[j] == s3[i + j]) {
      bool check = recur(s1, i, s2, j + 1, s3);
      if (check) {
        return true;
      }
    }
    dp_[i][j] = 0;
    return false;
  }

private:
  vector<vector<int>> dp_;
};
