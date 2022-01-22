// http://leetcode.com/problems/satisfiability-of-equality-equations/description/
#include "xxx.hpp"

class Solution {
public:
  bool equationsPossible(vector<string> &equations) {
    unordered_map<char, unordered_set<char>> equals;
    vector<pair<char, char>> paradox;
    for (auto &s : equations) {
      auto char1 = s[0];
      auto char2 = s[3];
      if (s[1] == '!') {
        if (char1 == char2) {
          return false;
        }
        paradox.push_back({char1, char2});
      } else {
        equals[char1].insert(char2);
        equals[char2].insert(char1);
      }
    }

    for (auto p : paradox) {
      unordered_set<char> visil;
      dfs(equals, visil, p.first);
      unordered_set<char> visir;
      dfs(equals, visir, p.second);
      // 两边集合是不相交的
      for (auto l : visil) {
        if (visir.find(l) != visir.end()) {
          return false;
        }
      }
    }

    return true;
  }
  void dfs(unordered_map<char, unordered_set<char>> &eqs,
           unordered_set<char> &visited, char cur) {
    if (visited.find(cur) != visited.end()) {
      return;
    }

    visited.insert(cur);
    for (auto ch : eqs[cur]) {
      dfs(eqs, visited, ch);
    }
  }
};
int main() {
  Solution so;
  vector<string> input{"a!=d", "a==d", "f==c"};
  so.equationsPossible(input);
}
