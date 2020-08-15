// http://leetcode.com/problems/restore-the-array/description/
#include "xxx.h"

class Solution {
public:
  int numberOfArrays(string s, int k) {
    vector<int> dp(s.size(), -1);
    return dfs(s, k, 0, dp);
  }

private:
  int dfs(string &s, int k, int cur, vector<int> &dp) {
    if (cur == s.size()) {
      return 1;
    }
    if (s[cur] == '0') {
      return 0;
    }
    if (dp[cur] != -1) {
      return dp[cur];
    }

    int ret = 0;
    long num = 0;
    for (int j = cur; j < s.size(); ++j) {
      num = num * 10 + s[j] - '0';
      if (num > k) {
        break;
      }
      ret += dfs(s, k, j + 1, dp);
      ret %= long(1e9 + 7);
    }

    dp[cur] = ret;
    return ret;
  }
};
