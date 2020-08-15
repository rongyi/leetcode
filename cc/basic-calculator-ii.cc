// https://leetcode.com/problems/basic-calculator-ii/description/
#include "xxx.h"
class Solution {
public:
  int calculate(string s) {
    auto tks = tokenize(s);
    stack<int> stack;
    int ret = 0;
    const int n = tks.size();

    string prev_op{"+"};
    for (int i = 0; i < n; ++i) {
      if (tks[i] == "+") {
        prev_op = "+";
      } else if (tks[i] == "-") {
        prev_op = "-";
      } else if (tks[i] == "*" || tks[i] == "/") {
        int cur = stack.top();
        stack.pop();
          int b = stoi(tks[i + 1]);
        if (tks[i] == "*") {
          stack.push(cur * b);
        } else {
          stack.push(cur / b);
        }
        // ignore next
        ++i;
      } else {
        int cur = stoi(tks[i]);
        if (prev_op == "+") {
          stack.push(cur);
        } else {
          stack.push(-1*cur);
        }
      }
    }
    while (!stack.empty()) {
      ret += stack.top();
      stack.pop();
    }

    return ret;
  }



  int calculateTLE(string s) {
    auto tks = tokenize(s);
    const int n = tks.size();
    stack<string> stack;

    auto doop = [](string &op1, string &op, string &op2) -> string {
      auto a = stoi(op1);
      auto b = stoi(op2);
      if (op == "+") {
        return to_string(a + b);
      } else if (op == "-") {
        return to_string(a - b);
      } else if (op == "*") {
        return to_string(a * b);
      } else {
        return to_string(a / b);
      }
    };

    for (int i = 0; i < n;) {
      if (tks[i] == "*" || tks[i] == "/") {
        auto op1 = stack.top();
        stack.pop();
        auto op2 = tks[i + 1];
        auto inter_ret = doop(op1, tks[i], op2);
        stack.push(inter_ret);

        i += 2;
      } else {
        stack.push(tks[i]);
        i++;
      }
    }
    // now we have flat stack

    vector<string> flat;

    while (!stack.empty()) {
      flat.insert(flat.begin(), stack.top());
      stack.pop();
    }
    return flatop(flat);
  }

private:
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
        // '+' '-' '/' '*'
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
  string input{" 3+5 / 2 "};
  auto tks = so.tokenize(input);
  for (auto t : tks) {
    cout << t << endl;
  }
  auto ret = so.calculateTLE(input);
  cout << ret << endl;
}
