// http://leetcode.com/problems/remove-outermost-parentheses/description/
#include "xxx.h"

class Solution {
public:
  string removeOuterParentheses(string s) {
    const int n = s.size();
    stack<int> stk;

    ostringstream ss;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        stk.push(i);
      } else {
        auto start = stk.top();
        stk.pop();
        // 证明这是最外层的
        if (stk.empty()) {
          ss << s.substr(start + 1, i - start - 1);
        }
      }
    }
    return ss.str();
  }
};
