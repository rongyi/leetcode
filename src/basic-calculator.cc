// https://leetcode.com/problems/basic-calculator/description/
#include "one.h"
class Solution {
public:
  int calculate(string s) {
    stack<int> stack;
    auto tks = tokenize(s);
    int ret = 0;
    int sign = 1;
    for (auto tk : tks) {
      if (tk == "+") {
        sign = 1;
      } else if (tk == "-") {
        sign = -1;
      } else if (tk == "(") {
        stack.push(ret);
        stack.push(sign);
        ret = 0;
        sign = 1;
      } else if (tk == ")") {
        ret *= stack.top();
        stack.pop();
        ret += stack.top();
        stack.pop();
      } else { // number
        // sign 是结合给后面的数字的,也就是现在用
        ret += sign * stoi(tk);
        sign = 1;
      }
    }
    return ret;
  }
  // assume the give expression is always valid, yeah
  int calculateRongYi(string s) {
    stack<string> opstack;
    auto tks = tokenize(s);
    const int n = tks.size();
    for (int i = 0; i < n; ++i) {
      if (tks[i] == ")") {
        vector<string> flat;
        while (opstack.top() != "(") {
          auto cur = opstack.top();
          opstack.pop();
          flat.insert(flat.begin(), cur);
        }
        // pop the left parenthesis
        opstack.pop();
        // push the calculated result
        opstack.push(to_string(flatop(flat)));
      } else {
        opstack.push(tks[i]);
      }
    }

    // now we have a flat
    vector<string> flat;

    while (!opstack.empty()) {
      flat.insert(flat.begin(), opstack.top());
      opstack.pop();
    }
    return flatop(flat);
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
  int flatop(vector<string> &ops) {
    if (ops.size() == 1) {
      return stoi(ops[0]);
    }
    int prev = numeric_limits<int>::min();
    int ret = 0;
    const int n = ops.size();
    for (int i = 1; i < n;) {
      if (prev == numeric_limits<int>::min()) {
        prev = stoi(ops[i - 1]);
      } else {
        prev = ret;
      }
      if (ops[i] == "+" || ops[i] == "-") {
        if (ops[i] == "+") {
          ret = prev + stoi(ops[i + 1]);
        } else {
          ret = prev - stoi(ops[i + 1]);
        }
        i += 2;
      } else {
        ++i;
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  // string input{"(1+(4+5+2)-3)+(6+8)"};
  // auto tks = so.tokenize(input);
  // for (auto t : tks) {
  //   cout << t << endl;
  // }
  // auto ret = so.calculate(input);
  // cout << ret << endl;

  vector<string> input{"1", "+", "11", "-", "3"};
  auto ret = so.flatop(input);
  cout << ret << endl;
}
