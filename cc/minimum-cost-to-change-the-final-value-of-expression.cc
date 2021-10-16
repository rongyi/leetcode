// http://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression/description/
#include "xxx.h"

class Solution {
public:
  int minOperationsToFlip(string expr) {
    using pci = pair<char, int>;
    stack<pci> s;

    pci right_mybe;
    char op;
    char val1;
    char val2;
    int cost1;
    int cost2;

    for (int i = 0; i < expr.size(); ++i) {
      auto cur = expr[i];
      if (cur == '(' || cur == '&' || cur == '|') {
        // useless for the second field
        s.push({cur, 0});
      } else {
        // the right oprand either comming from input or
        // sub expr i.e. the expr in '()'
        if (cur == ')') {
          // we'll comeback latter
          right_mybe = s.top(); // as a unit to join operation
          s.pop();
          s.pop(); // pop the '('
        } else {
          // we meet '0' or '1'
          // two cases:
          // 1. left oprand(top stack is not op || stack empty)
          // 2. right oprand(top stack is op)
          // the only 1 openrand case, change the result only
          // need to change 1 to 0 or change 0 to 1
          right_mybe = {cur, 1};
        }

        // need to eval, yes right_mybe is a right openrand
        if (!s.empty() && (s.top().first == '&' || s.top().first == '|')) {
          op = s.top().first;
          s.pop();
          val2 = right_mybe.first;
          cost2 = right_mybe.second;

          val1 = s.top().first;
          cost1 = s.top().second;
          s.pop();

          if (op == '&') {
            if (val1 == '1' && val2 == '1') {
              right_mybe = {'1', min(cost1, cost2)};
            }
            if (val1 == '1' && val2 == '0') {
              right_mybe = {'0', 1};
            }
            if (val1 == '0' && val2 == '1') {
              right_mybe = {'0', 1};
            }
            if (val1 == '0' && val2 == '0') {
              right_mybe = {'0', min(1 + cost1, 1 + cost2)};
            }
          } else {
            if (val1 == '1' && val2 == '1') {
              right_mybe = {'1', min(1 + cost1, 1 + cost2)};
            }
            if (val1 == '1' && val2 == '0') {
              right_mybe = {'1', 1};
            }
            if (val1 == '0' && val2 == '1') {
              right_mybe = {'1', 1};
            }
            if (val1 == '0' && val2 == '0') {
              right_mybe = {'0', min(cost1, cost2)};
            }
          }
        }
        // otherwise just push to stack
        s.push(right_mybe);
      }
    }

    return s.top().second;
  }
};
