// https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/
#include "xxx.hpp"

class Solution {
public:
  // shitty problem: "1(2+3)4", and they call this a valid expression
  // this is so many downvote
  // what a fucking problem
  string minimizeResult(string expression) {
    vector<int> num1;
    vector<int> num2;
    int sz = expression.size();
    int plus_pos = -1;

    int i = 0;
    for (; i < sz; ++i) {
      if (expression[i] == '+') {
        break;
      }
      num1.push_back(expression[i] - '0');
    }
    // jump over +
    plus_pos = i;
    i++;
    for (; i < sz; ++i) {
      num2.push_back(expression[i] - '0');
    }

    vector<int> sec1(num1.size() + 1);
    vector<int> sec2(num2.size() + 1);

    for (int i = num1.size() - 1, base = 1; i >= 0; --i) {
      sec1[i] = base * num1[i] + sec1[i + 1];
      base *= 10;
    }

    for (int i = num2.size() - 1, base = 1; i >= 0; --i) {
      sec2[i] = base * num2[i] + sec2[i + 1];
      base *= 10;
    }

    int min_sum = sec1[0] + sec2[0];
    int min_idx_i = -1;
    int min_idx_j = -1;
    // take 247+38 as example
    // num1 [2, 4, 7]
    // num2 [3, 8]
    // sec1 [247, 47, 7, 0]
    // sec2 [38, 8, 0]
    // notice the boundary chec, this is ugly
    // so put ( at each num's left
    for (int i = 0, prevl = 0; i < num1.size(); ++i) {
      int multi1 = (i == 0) ? 1 : (prevl * 10) + num1[i - 1];

      // put ) at each nums'right
      for (int j = 0, prevr = 0; j < num2.size(); ++j) {
        int multi2 = (j == num2.size() - 1) ? 1 : sec2[j + 1];
        int right = prevr * 10 + num2[j];
        int mid_sum = /*left*/ sec1[i] + /*right*/ right;
        int cur_sum = multi1 * mid_sum * multi2;

        if (cur_sum < min_sum) {
          min_sum = cur_sum;
          min_idx_i = i;
          min_idx_j = j;
        }

        prevr = right;
      }

      // sick check! fuck, don't count when index is 0
      // at index 1, we have prev = multi1
      prevl = (i == 0) ? 0 : multi1;
    }

    if (min_idx_i == -1 && min_idx_j == -1) {
      return "(" + expression + ")";
    }
    string op1 = expression.substr(0, plus_pos);
    string op2 = expression.substr(plus_pos + 1);
    // left ( is put at the num left, so just the index is fine
    op1.insert(op1.begin() + min_idx_i, '(');
    // but right ) is put at num right, so need to plus 1
    op2.insert(op2.begin() + min_idx_j + 1, ')');

    return op1 + "+" + op2;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  cout << so.minimizeResult("247+38") << endl;
  return 0;
}
