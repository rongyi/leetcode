// http://leetcode.com/problems/longest-valid-parentheses/description/
#include "xxx.h"
class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> stk;
    int ret = 0;
    int start = 0;
    const int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        stk.push(i);
      } else {
        // this is not valid
        if (stk.empty()) {
          start = i + 1;
        } else {
          stk.pop();
          if (stk.empty()) {
            ret = max(ret, i - start + 1);
          } else {
            ret = max(ret, i - stk.top());
          }
        }
      }
    }
    return ret;
  }
};
int main() {
  Solution so;
  so.longestValidParentheses(")()())");
}
