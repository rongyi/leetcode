// http://leetcode.com/problems/baseball-game/description/
#include "xxx.hpp"

class Solution {
public:
  // 跟着题目走即可
  int calPoints(vector<string> &ops) {
    stack<int> stk;
    for (auto score : ops) {
      if (score == "C") {
        stk.pop();
      } else if (score == "D") {
        auto n1 = stk.top();
        stk.push(n1 * 2);
      } else if (score == "+") {
        auto n1 = stk.top();
        stk.pop();
        auto n2 = stk.top();
        auto n3 = n1 + n2;
        stk.push(n1);
        stk.push(n3);
      } else {
        stk.push(stoi(score));
      }
    }
    int ret = 0;

    while (!stk.empty()) {
      ret += stk.top();
      stk.pop();
    }

    return ret;
  }
};
