// http://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
#include "xxx.hpp"

class Solution {
public:
  int minAddToMakeValid(string S) {
    // 需要脑补左括号的个数
    int left = 0;
    // 需要脑补右括号的个数
    int right = 0;
    stack<char> stk;

    for (auto c : S) {
      if (c == '(') {
        stk.push('(');
      } else {
        // 照道理遇到 )应该弹出来对应的 (
        // 可万一没有呢，就脑补一个 (
        if (stk.empty()) {
          left++;
        } else {
          stk.pop();
        }
      }
    }
    // 栈里面剩下的( 都是没人匹配的，再脑补这么多的 )吧
    right = stk.size();
    return left + right;
  }
};
