// http://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/
#include "xxx.hpp"

class Solution {
public:
  string minRemoveToMakeValid(string s) {
    unordered_set<int> invalid_index;

    stack<int> stk;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        stk.push(i);
      } else if (s[i] == ')') {
        // then this ) is not valid
        if (stk.empty()) {
          invalid_index.insert(i);
        } else {
          stk.pop();
        }
      }
    }
    // left in stack is not valid
    while (!stk.empty()) {
      invalid_index.insert(stk.top());
      stk.pop();
    }
    string ret;
    for (int i = 0; i < s.size(); ++i) {
      if (invalid_index.find(i) == invalid_index.end()) {
        ret.push_back(s[i]);
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  cout << so.minRemoveToMakeValid("lee(t(c)o)de)") << endl;
}
