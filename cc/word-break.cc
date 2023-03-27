// http://leetcode.com/problems/word-break/description/

#include "xxx.hpp"

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    set<string> ws(wordDict.begin(), wordDict.end());
    int sz = s.size();
    // dp[i] -> len is i
    vector<int> dp(sz + 1, 0);
    dp[0] = 1;

    for (int l = 1; l <= sz; l++) {
      for (int i = 0; i < l; i++) {
        // [0...i....l+1]
        if (dp[i] && ws.count(s.substr(i, l - i))) {
          dp[l] = true;
          break;
        }
      }
    }

    return dp[sz];
  }

private:
  bool dobreak(string s, set<string> &ws) {
    if (s.empty()) {
      return true;
    }
    for (int l = 1; l <= s.size(); l++) {
      string cur = s.substr(0, l);
      if (ws.count(cur)) {
        int ok = dobreak(s.substr(l), ws);
        if (ok) {
          return ok;
        }
      }
    }
    return false;
  }
};
