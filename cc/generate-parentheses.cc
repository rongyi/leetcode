// http://leetcode.com/problems/generate-parentheses/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    cache_.clear();
    recur(n, n, "");

    return cache_;
  }

private:
  void recur(int l, int r, string cur) {
    if (l == 0 && r == 0) {
      cache_.push_back(cur);
    }
    if (l > 0) {
      recur(l - 1, r, cur + '(');
    }
    if (r > 0 && l < r) {
      recur(l, r - 1, cur + ')');
    }
  }

private:
  vector<string> cache_;
};
