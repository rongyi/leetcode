// http://leetcode.com/problems/word-break-ii/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    set<string> ws(wordDict.begin(), wordDict.end());

    int sz = s.size();
    vector<int> dp(sz + 1, 0);
    dp[0] = 1;

    // dp2[l][i]  len is l at i pos
    vector<vector<int>> dp2(sz + 1, vector<int>(sz + 1, 0));

    for (int l = 1; l <= sz; l++) {
      for (int i = 0; i < l; i++) {
        string cur = s.substr(i, l - i);
        if (dp[i - 1 + 1] && ws.count(cur)) {
          dp[l] = 1;
          dp2[l][i] = 1;
        }
      }
    }

    vector<string> ret;
    vector<string> path;

    recur(s, ws, dp2, ret, path, sz);

    return ret;
  }

private:
  void recur(string &s, set<string> &ws, vector<vector<int>> &dp,
             vector<string> &ret, vector<string> &path, int pos) {
    if (pos == 0) {
      string setc;
      for (int i = path.size() - 1; i >= 0; i--) {
        setc += path[i] + " ";
      }
      setc.pop_back();
      ret.push_back(setc);
      return;
    }

    for (int i = 0; i < s.size(); i++) {
      if (dp[pos][i]) {
        string cur = s.substr(i, pos - i);

        path.push_back(cur);

        recur(s, ws, dp, ret, path, i);

        path.pop_back();
      }
    }
  }
};
