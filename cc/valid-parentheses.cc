// http://leetcode.com/problems/valid-parentheses/description/
#include "xxx.hpp"

class Solution {
public:
  bool isValid(string s) {
    map<char, char> p;
    p[')'] = '(';
    p[']'] = '[';
    p['}'] = '{';
    vector<char> stk;
    for (auto c : s) {
      if (c == '(' || c == '[' || c == '{') {
        stk.push_back(c);
      } else {
        if (stk.empty()) {
          return false;
        }
        if (p[c] != stk.back()) {
          return false;
        }
        stk.pop_back();
      }
    }

    return stk.empty();
  }
};
