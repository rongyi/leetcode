// http://leetcode.com/problems/generate-parentheses/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> ret;
    string s{""};
    rec(n, n, s, ret);
    return ret;
  }

private:
  void rec(int left, int right, string cur, vector<string> &ret) {
    if (left == 0 && right == 0) {
      ret.push_back(cur);
    }
    if (left > 0) {
      rec(left - 1, right, cur + "(", ret);
    }
    // 表示 ')' 不可以先进来
    if (right > 0 && left < right) {
      rec(left, right - 1, cur + ")", ret);
    }
  }
};
