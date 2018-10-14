// http://leetcode.com/problems/palindrome-partitioning/description/
#include "one.h"

class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ret;
    vector<string> cur;

    dfs(s, ret, cur);

    return ret;
  }

private:
  void dfs(string s, vector<vector<string>> &ret, vector<string> &cur) {
    if (s.empty()) {
      ret.push_back(cur);
      return;
    }
    for (int i = 1; i <= s.size(); i++) {
      string tmp = s.substr(0, i);
      if (isParlidrome(tmp)) {
        cur.push_back(tmp);
        dfs(s.substr(i), ret, cur);
        cur.pop_back();
      }
    }
  }
  bool isParlidrome(const string s) {
    if (s.empty() || s.size() == 1) {
      return true;
    }

    const int len = s.size();
    for (int i = 0; i < len / 2; i++) {
      if (s[i] != s[len - i - 1])
        return false;
    }

    return true;
  }
};
