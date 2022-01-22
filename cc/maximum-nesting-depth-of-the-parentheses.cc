// http://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
#include "xxx.hpp"

class Solution {
public:
  int maxDepth(string s) {
    vector<char> stk;
    int ret = 0;

    for (auto c : s) {
      if (c == '(') {
        stk.push_back('(');
        ret = max(ret, int(stk.size()));
      } else if (c == ')') {
        stk.pop_back();
      }
    }

   return ret;
  }
};
