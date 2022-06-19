// https://leetcode.com/problems/match-substring-after-replacement/
#include "xxx.hpp"

class Solution {
public:
  bool matchReplacement(string s, string sub, vector<vector<char>> &mappings) {
    map<char, set<char>> ch;
    for (auto &p : mappings) {
      ch[p[0]].insert(p[1]);
    }
    for (int i = 0; i + sub.size() <= s.size(); ++i) {
      int j = 0;
      for (; j < sub.size(); ++j) {
        if (sub[j] != s[i + j] && ch[sub[j]].count(s[i + j]) == 0) {
          break;
        }
      }
      if (j == sub.size()) {
        return true;
      }
    }

    return false;
  }
};
