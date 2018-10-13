// http://leetcode.com/problems/distinct-subsequences/description/
#include "one.h"

class Solution {
public:
  int numDistinct(string s, string t) {
    const int n = s.size();
    const int m = t.size();

    vector<int> dp(n + 1, 1);

    for (int i = 1; i <= m; i++) {
      int up_left = dp[0];
      dp[0] = 0;
      for (int j = 1; j <= n; j++) {
        int tmp = dp[j];
        dp[j] = dp[j - 1];
        if (s[j - 1] == t[i - 1]) {
          dp[j] += up_left;
        }
        up_left = tmp;
      }
    }
    return dp[n];
  }
};
