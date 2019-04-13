// http://leetcode.com/problems/solve-the-equation/description/
#include "xxx.h"

class Solution {
  struct Equation {
    int co_;
    int sum_;
  };

public:
  string solveEquation(string equation) {
    auto left = equation.substr(0, equation.find('='));
    auto right = equation.substr(equation.find('=') + 1);

    auto leqt = reduce(left);
    auto reqt = reduce(right);

    if (leqt.co_ == reqt.co_) {
      if (leqt.sum_ == reqt.sum_) {
        return "Infinite solutions";
      }
      return "No solution";
    }

    // ax + b = cx + d
    // ==> (a - c)x = (d - b)
    // ==> x = (d - b) / (a - c)
    auto co = leqt.co_ - reqt.co_;
    auto sum = reqt.sum_ - leqt.sum_;
    return "x=" + to_string(sum / co);
  }
  Equation reduce(string eqs) {
    auto isop = [](char c) -> bool { return c == '+' || c == '-'; };
    // 总是保持 +x-3+5这样的队形，第一个如果为正而且又没有则添加上来
    // 方便后面的parser
    if (!isop(eqs[0])) {
      eqs = '+' + eqs;
    }
    const int n = eqs.size();
    Equation eqt{0, 0};
    int i = 0;
    while (i < n) {
      // jump over
      int j = i + 1;
      char op = eqs[i];
      while (j < n && !isop(eqs[j])) {
        j++;
      }
      // j会停留在下一个操作符上，或者是结束
      string cur = eqs.substr(i + 1, j - i - 1);
      // cout << cur << endl;
      bool has_x = cur.find('x') != string::npos;
      if (op == '+') {
        if (has_x) {
          if (cur == "x") {
            eqt.co_ += 1;
          } else {
            string s = cur.substr(0, cur.size() - 1);
            eqt.co_ += stoi(s);
          }
        } else {
          eqt.sum_ += stoi(cur);
        }
      } else {
        if (has_x) {
          if (cur == "x") {
            eqt.co_ -= 1;
          } else {
            string s = cur.substr(0, cur.size() - 1);
            eqt.co_ -= stoi(s);
          }
        } else {
          eqt.sum_ -= stoi(cur);
        }
      }
      i = j;
    }
    return eqt;
  }
};

int main() {
  Solution so;
  auto ret = so.reduce("x+5-3+3x");
  cout << "co_ is: " << ret.co_ << ": and sum: " << ret.sum_ << endl;
}
