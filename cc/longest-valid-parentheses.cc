// http://leetcode.com/problems/longest-valid-parentheses/description/
#include "xxx.hpp"
class Solution {
public:
  int longestValidParentheses(string s) {
    int sz = s.size();
    vector<int> stk;
    int valid_start = 0;
    int ret = 0;
    for (int i = 0; i < sz; ++i) {
      if (s[i] == '(') {
        stk.push_back(i);
      } else {
        if (stk.empty()) {
          valid_start = i + 1;
        } else {
          stk.pop_back();
          if (stk.empty()) {
            ret = max(ret, i - valid_start + 1);
          } else {
            ret = max(ret, i - (stk.back() + 1) + 1);
          }
        }
      }
    }
    return ret;
  }
};
