// http://leetcode.com/problems/score-of-parentheses/description/
#include "xxx.hpp"

class Solution {
public:
  int scoreOfParentheses(string S) {
    // 用栈来模拟，遇到左就push
    // 遇到 ) 分两种情况： 产生1没？
    // 怎么判断最内层括号的那个1？
    // 就是判断栈顶是不是 '(' 如果是，则没产生，如果不是
    // 那么赶紧把所有数字都搞出来加一把，然后把匹配的左侧 '('
    // 也给弹出来，计算好再入进去
    stack<int> stk;
    for (auto c : S) {
      if (c == '(') {
        stk.push('(');
      } else {
        if (stk.top() == '(') {
          stk.pop();
          stk.push(1);
        } else {
          int cur_sum = 0;
          while (!stk.empty() && stk.top() != '(') {
            cur_sum += stk.top();
            stk.pop();
          }
          // the outer left (
          stk.pop();
          stk.push(cur_sum * 2);
        }
      }
    }

    int ret = 0;
    // 结果是一堆散的
    while (!stk.empty() && stk.top() != '(') {
      ret += stk.top();
      stk.pop();
    }
    // the last ( is still in here
    return ret;
  }
};

int main() {
  Solution so;
  cout << so.scoreOfParentheses("(()(()))") << endl;
}
