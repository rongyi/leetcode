// http://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/description/
#include "xxx.h"

class Solution {
public:
  int minInsertions(string s) {
    int ret = 0;
    vector<char> stk;
    for (int i = 0; i < s.size();) {
      // expect two other ))
      if (s[i] == '(') {
        stk.push_back('(');
        i++;
      } else {
        // expect ) after and prev (
        if (stk.empty()) {
          // insert (
          ret++;
          // 脑补一个，再继续这轮，所以有点慢
          // stk.push_back('(');

          // 优化上面的脑补
          // 满足要求
          if (i + 1 < s.size() && s[i + 1] == ')') {
            i += 2;
          } else {
            // 差一个 )补齐，从下一个开始
            ret++;
            i++;
          }
        } else {
          stk.pop_back();
          if (i + 1 < s.size() && s[i + 1] == ')') {
            i += 2;
          } else {
            ret++;
            i++;
          }
        }
      }
    }
    ret += stk.size() * 2;
    return ret;
  }
};
