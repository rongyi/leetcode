// http://www.lintcode.com/zh-cn/problem/number-of-atoms

#include "one.h"
class Solution {
public:
  string countOfAtoms(string formula) {
    stack<string> stk;
    const int n = formula.size();
    for (int i = 0; i < n;) {
      if (formula[i] == '(') {
        stk.push("(");
        i++;
      } else if (formula[i] == ')') {
        i++;
      } else {
        int j = i + 1;
        while (j < n && islower(formula[j])) {
          j++;
        }
        string ele{""};
        // only captial element
        if (j == (i + 1)) {
          ele = formula[i];
        } else {
          ele = formula.substr(i, j);
        }
        cout << ele << " ";

        int k = j;
        while (k < n && isdigit(formula[k])) {
          k++;
        }
        int num = 1;
        if (k != j) {
          num = stoi(formula.substr(j, k));
        }
        cout << num << endl;
        i = k;
      }
    }
    return "";
  }

public:
  string multiply(string &s, int n) {
    string ele = s.substr(0, s.find(':'));
    int count = stoi(s.substr(s.find(':') + 1));
    return ele + ":" + to_string(count * n);
  }
};
int main() {
  Solution so;
  string input{"K4(ON(SO3)2)2"};
  auto ret = so.countOfAtoms(input);
  cout << ret << endl;

  // input = "S:32";
  // auto ret = so.multiply(input, 2);
  // cout << ret << endl;
}
