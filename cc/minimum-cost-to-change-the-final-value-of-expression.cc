// http://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression/description/
#include "xxx.hpp"

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
        // we get right openrand from input or the eval of sub expr

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
            // change one of 1 to 0
            if (val1 == '1' && val2 == '1') {
              right_mybe = {'1', min(cost1, cost2)};
            }
            // 1 & 0 change & ==> |
            if (val1 == '1' && val2 == '0') {
              right_mybe = {'0', 1};
            }
            // 0 & 1 change & ==> |
            if (val1 == '0' && val2 == '1') {
              right_mybe = {'0', 1};
            }
            // 0 & 0 change & ==> | and change one of them to 1
            if (val1 == '0' && val2 == '0') {
              right_mybe = {'0', min(1 + cost1, 1 + cost2)};
            }
          } else {
            // 1 | 1 change | ==> 0 and change one of them to 1
            if (val1 == '1' && val2 == '1') {
              right_mybe = {'1', min(1 + cost1, 1 + cost2)};
            }
            // 1 | 0 change | ==> &
            if (val1 == '1' && val2 == '0') {
              right_mybe = {'1', 1};
            }
            // 0 | 1 change | ==> &
            if (val1 == '0' && val2 == '1') {
              right_mybe = {'1', 1};
            }
            // 0 | 0 change one of them to 1
            if (val1 == '0' && val2 == '0') {
              right_mybe = {'0', min(cost1, cost2)};
            }
          }
        }
        // this value is eighter right or finaly value applied stack top op
        s.push(right_mybe);
      }
    }

    return s.top().second;
  }
};

int main() {
  string input{"1&(0&1)"};
  stack<char> s;

  auto apply = [&](char right) {
    if (!s.empty() && (s.top() == '|' || s.top() == '&')) {
      auto op = s.top();
      s.pop();
      auto val1 = s.top();
      s.pop();
      if (op == '&') {
        if (right == '1' && val1 == '1') {
          s.push('1');
        } else {
          s.push('0');
        }
      } else {
        // op |
        if (right == '1' || val1 == '1') {
          s.push('1');
        } else {
          s.push('0');
        }
      }
    } else {
      s.push(right);
    }
  };
  for (int i = 0; i < input.size(); ++i) {
    auto cur = input[i];
    if (cur == '(' || cur == '|' || cur == '&') {
      s.push(cur);
    } else {
      if (cur == ')') {
        cur = s.top();
        s.pop();
        s.pop(); // drop (
        apply(cur);

      } else {
        // 0 or 1,this may be the right openrand, so
        // if so, we eval
        // else just push to stack
        apply(cur);
      }
    }
  }
  cout << s.top() << endl;
}
