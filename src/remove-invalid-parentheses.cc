// http://leetcode.com/problems/remove-invalid-parentheses/description/
#include "xxx.h"

class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> ret;
    remove(s, 0, 0, '(', ')', ret);

    return ret;
  }
private:
  void remove(string s, int last_valid, int last_remove, const char open, const char close, vector<string> &ret) {
    int paren_count = 0;
    for (int i = last_valid; i < s.size(); i++) {
      if (s[i] == open) {
        paren_count++;
      }
      if (s[i] == close) {
        paren_count--;
      }
      if (paren_count < 0) {
        for (int j = last_remove; j <= i; ++j) {
          if (s[j] == close && (j == last_remove || s[j - 1] != close)) {
            remove(s.substr(0, j) + s.substr(j + 1), i, j, open, close, ret);
          }
        }
        return;
      }
    }

    // if we reach here, current s is valid without any fix.
    // But each s should go through two pass, the second pass is for reversed string.
    // so we need to check if this is the first pass, if yes, reverse s and check again
    // if this is second pass, just save result
    // how to check if it's first pass? use the order of open/close Parentheses as flag
    if (open == '(') {
      reverse(s.begin(), s.end());
      remove(s, 0, 0, ')', '(', ret);
    } else {
      reverse(s.begin(), s.end());
      ret.push_back(s);
    }
  }
};

int main() {
  Solution so;
  auto ret = so.removeInvalidParentheses("()())()");
  for (auto s : ret) {
    cout << s << endl;
  }
}
