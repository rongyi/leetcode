// http://leetcode.com/problems/score-of-parentheses/description/
#include "xxx.hpp"
#include <vector>

class Solution {
public:
  int scoreOfParentheses(string S) {
    vector<int> stack(1, 0);

    for (auto c : S) {
      if (c == '(') {
        stack.push_back(0);
      } else {
        auto last = stack.back();
        stack.pop_back();
        stack.back() += max(2 * last, 1);
      }
    }

    return stack[0];
  }
};

int main() {
  Solution so;
  cout << so.scoreOfParentheses("(()(()))") << endl;
}
