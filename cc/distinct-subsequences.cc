// http://leetcode.com/problems/distinct-subsequences/description/
#include "xxx.h"

class Solution {
public:
  /**
   * @param S, T: Two string.
   * @return: Count the number of distinct subsequences
   * 子串的长度为 i，我们要求的就是长度为 i 的子串在长度为 j
   * 的母串中出现的次数，设为 t[i][j]
   * 若母串的最后一个字符与子串的最后一个字符不同，则长度为 i 的子串在长度为 j
   * 的母串中出现的次数就是母串的前 j - 1个字符中子串出现的次数，即
   * t[i][j] = t[i][j - 1]，
   * 若母串的最后一个字符与子串的最后一个字符相同，
   * 那么除了前 j - 1 个字符出现子串的次数外，
   * 还要加上子串的前 i - 1 个字符在母串的前j - 1个字符中出现的次数，即
   * t[i][j] = t[i][j - 1] + t[i - 1][j - 1]
   */
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
