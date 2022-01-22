// http://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/
#include "xxx.hpp"

class Solution {
public:
  int numSteps(string s) {
    int steps = 0;
    while (s != "1") {
      if (s.back() == '0') {
        s.pop_back();
      } else {
        int carry = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
          if (carry == 0) {
            break;
          }
          auto sum = (s[i] - '0') + carry;
          carry = sum / 2;
          s[i] = sum % 2 + '0';
        }
        if (carry) {
          s.insert(s.begin(), '1');
        }
      }

      steps++;
    }

    return steps;
  }
};
int main() {
  Solution so;
  so.numSteps("hello");
}
