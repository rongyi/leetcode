// https://leetcode.com/problems/basic-calculator/description/
#include "xxx.hpp"

class Solution {
public:
  int calculate(string s) {
    int sz = s.size();

    int sum = 0;
    int sign = 1;
    // {prev_sum, sign for peek value}
    stack<pair<int, int>> stk;

    for (int i = 0; i < sz; i++) {
      if (isdigit(s[i])) {
        int num = 0;
        int j = i;
        while (j < sz && isdigit(s[j])) {
          num = num * 10 + (s[j] - '0');
          j++;
        }
        // don't forget the outer i++
        // so we make i one more step back
        i = j - 1;
        // ignore '+' to make it through
        // so here the sum is accumulated
        sum += num * sign;
        sign = 1;
      } else if (s[i] == '-') {
        sign = -sign;
      } else if (s[i] == '(') {
        stk.push({sum, sign});
        sum = 0;
        sign = 1;
      } else if (s[i] == ')') {
        sum = stk.top().first + (stk.top().second * sum);
        stk.pop();
      }
    }

    return sum;
  }
};
