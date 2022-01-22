// https://leetcode.com/problems/valid-parenthesis-string/description/

#include "xxx.hpp"
class Solution {
public:
  bool checkValidString(string s) {
    stack<int> left;
    stack<int> star;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        left.push(i);
      } else if (s[i] == '*') {
        star.push(i);
      } else {
        if (left.empty() && star.empty()) {
          return false;
        }
        if (left.empty()) {
          star.pop();
        } else {
          left.pop();
        }
      }
    }

    while (!left.empty() && !star.empty()) {
      // *( 这种情况死都救不回来
      if (left.top() > star.top()) {
        return false;
      }
      left.pop();
      star.pop();
    }
    return left.empty();
  }
};
