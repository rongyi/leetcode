// https://leetcode.com/problems/extra-characters-in-a-string/
#include "xxx.hpp"

class Solution {
public:
  int minExtraChar(string s, vector<string> &dictionary) {
    set<string> uniq;
    for (auto &s : dictionary) {
      uniq.insert(s);
    }
    int sz = s.size();
    vector<int> dp(sz + 1, -1);

    return dfs(s, 0, uniq, dp);
  }

private:
  int dfs(string &s, int idx, set<string> &uniq, vector<int> &dp) {
    if (idx >= s.size()) {
      return 0;
    }
    if (dp[idx] != -1) {
      return dp[idx];
    }
    // skip one char
    int ret = 1 + dfs(s, idx + 1, uniq, dp);
    for (int i = 1; idx + i <= s.size(); i++) {
      string cur = s.substr(idx, i);
      if (uniq.count(cur)) {
        ret = min(ret, dfs(s, idx + i, uniq, dp));
      }
    }

    return dp[idx] = ret;
  }
};
