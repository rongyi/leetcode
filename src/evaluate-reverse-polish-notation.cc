// http://leetcode.com/problems/evaluate-reverse-polish-notation/description/
#include "xxx.h"

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> stk;
    for (unsigned i = 0; i < tokens.size(); ++i) {
      auto cur = tokens[i];
      if (cur == "+" || cur == "-" || cur == "*" || cur == "/") {
        auto op2 = stk.top();
        stk.pop();
        auto op1 = stk.top();
        stk.pop();
        auto opret = 0;
        if (cur == "+") {
          opret = op1 + op2;
        } else if (cur == "-") {
          opret = op1 - op2;
        } else if (cur == "*") {
          opret = op1 * op2;
        } else {
          opret = op1 / op2;
        }
        stk.push(opret);
      } else {
        stk.push(stoi(cur));
      }
    }

    return stk.top();
  }
};
