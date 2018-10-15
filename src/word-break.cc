// http://leetcode.com/problems/leetcode/word-break/description/
#include "one.h"
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    const int n = s.size();
    // the real word dict
    unordered_set<string> ws;
    for (auto &w : wordDict) {
      ws.insert(w);
    }
    vector<bool> dp(n + 1, false);
    // empty string case
    dp[0] = true;

    // [0..j..i]之间选取一个点，这个点前一段是dp[j]后一段是
    // substr(j, i - j)，如果前一段为true 后一段能在字典
    // 里找到说明可以切
    for (int i = 0; i < n + 1; ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[j] && ws.count(s.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }

    return dp[n];
  }
};
