// http://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/
#include "xxx.h"

class Solution {
public:
  string reverseParentheses(string s) {
    stack<int> stk;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        stk.push(i);
      } else if (s[i] == ')') {
        auto begin = stk.top();
        stk.pop();
        reverse(s.begin() + begin + 1, s.begin() + i);
      }
    }
    string ret{};
    for (auto &c : s) {
      if (c != ')' && c != '(') {
        ret.push_back(c);
      }
    }
    return ret;
  }
};
