// http://leetcode.com/problems/evaluate-reverse-polish-notation/description/
#include "xxx.hpp"

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> s;
    for (auto &tok : tokens) {
      if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
        auto v1 = s.top();
        s.pop();
        auto v2 = s.top();
        s.pop();
        if (tok == "+") {
          s.push(v1 + v2);
        } else if (tok == "-") {
          s.push(v2 - v1);
        } else if (tok == "*") {
          s.push(v1 * v2);
        } else {
          s.push(v2 / v1);
        }
      } else {
        s.push(stoi(tok));
      }
    }
    return s.top();
  }
};
