// https://leetcode.com/problems/basic-calculator/description/
#include "one.h"
class Solution {
public:
  // assume the give expression is always valid, yeah
  int calculate(string s) {
    int ret = 0;
    stack<string> opstack;
    auto tks = tokenize(s);
    const int n = tks.size();
    for (int i = 0; i < n; ++i) {
      if (tks[i] == ")") {
        auto op1 = opstack.top();
        opstack.pop();

        auto opt = opstack.top();
        opstack.pop();

        auto op2 = opstack.top();
        opstack.pop();
        // and the left parenthesis
        opstack.pop();

        if (opt == "+") {
          opstack.push(to_string(stoi(op1) + stoi(op2)));
        } else {
          opstack.push(to_string(stoi(op1) - stoi(op2)));
        }
      } else {
        opstack.push(tks[i]);
      }
    }

    while (!opstack.empty()) {
      auto op1 = opstack.top();
      opstack.pop();
      if (opstack.empty()) {
        return stoi(op1);
      }

      auto opt = opstack.top();
      opstack.pop();

      auto op2 = opstack.top();
      opstack.pop();
      if (opt == "+") {
        opstack.push(to_string(stoi(op1) + stoi(op2)));
      } else {
        opstack.push(to_string(stoi(op1) - stoi(op2)));
      }
    }
    return ret;
  }

public:
  vector<string> tokenize(string &s) {
    // try to parse the last digit
    s.push_back(' ');
    const int n = s.size();
    int i = 0;
    vector<string> ret;
    // ignore leading spaces
    while (s[i] == ' ') {
      ++i;
    }
    // we expect a digit
    bool in_digit = false;
    int start = 0;
    for (int j = i; j < n; ++j) {
      if (isdigit(s[j]) && !in_digit) {
        in_digit = true;
        start = j;
      }
      if (!isdigit(s[j])) {
        if (in_digit) {
          // not digit now
          in_digit = false;
          ret.push_back(s.substr(start, j - start));
        }
        // ignore spaces
        if (s[j] == ' ') {
          continue;
        }
        // '(' ')' '+' '-'
        ret.push_back({s[j]});
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  string input{"2-(5-6)"};
  auto tks = so.tokenize(input);
  for (auto t : tks) {
    cout << t << endl;
  }
  auto ret = so.calculate(input);
  cout << ret << endl;
}
