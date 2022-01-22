// http://leetcode.com/problems/valid-parentheses/description/
#include "xxx.hpp"

class Solution {
public:
  bool isValid(string s) {
    const string left{"([{"};
    const string right{")]}"};
    stack<char> stk;
    for (auto c : s) {
      if (c == '(' || c == '[' || c == '{') {
        stk.push(c);
      } else {
        if (stk.empty()) {
          return false;
        }
        auto tmp = stk.top();
        if (right.find(c) != left.find(tmp)) {
          return false;
        }
        stk.pop();
      }
    }

    return stk.empty();
  }
};
