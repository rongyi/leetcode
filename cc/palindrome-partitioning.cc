// http://leetcode.com/problems/palindrome-partitioning/description/
#include "xxx.hpp"

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
    for (int l = 1; l <= s.size(); l++) {
      string cut = s.substr(0, l);
      if (isParlidrome(cut)) {
        cur.push_back(cut);
        dfs(s.substr(l), ret, cur);
        cur.pop_back();
      }
    }
  }
  bool isParlidrome(string &s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }
};
