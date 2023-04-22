// https://leetcode.com/problems/basic-calculator-ii/description/
#include "xxx.hpp"

class Solution {
public:
  int calculate(string s) {
    auto tokens = tokenize(s);
    int sz = tokens.size();
    int sign = 1;
    stack<int> vals;

    for (int i = 0; i < sz; i++) {
      if (tokens[i] == "+") {
        sign = 1;
      } else if (tokens[i] == "-") {
        sign = -1;
      } else if (tokens[i] == "*" || tokens[i] == "/") {
        auto op1 = vals.top();
        vals.pop();
        // peek another op
        auto op2 = stoi(tokens[i + 1]);
        if (tokens[i] == "*") {
          vals.push(op1 * op2);
        } else {
          vals.push(op1 / op2);
        }
        sign = 1;
        // ignore the peek op2
        i++;
      } else {
        // number
        int val = stoi(tokens[i]);
        vals.push(sign * val);
        sign = 1;
      }
    }
    int sum = 0;
    while (!vals.empty()) {
      sum += vals.top();
      vals.pop();
    }
    return sum;
  }

private:
  vector<string> tokenize(string &s) {
    int sz = s.size();
    int i = 0;
    vector<string> tokens;
    while (i < sz) {
      if (isdigit(s[i])) {
        int j = i;
        while (j < sz && isdigit(s[j])) {
          j++;
        }
        string cur = s.substr(i, j - i);
        tokens.push_back(cur);

        // for i++ below
        i = j - 1;
      } else if (s[i] == '+') {
        tokens.push_back("+");
      } else if (s[i] == '-') {
        tokens.push_back("-");
      } else if (s[i] == '/') {
        tokens.push_back("/");
      } else if (s[i] == '*') {
        tokens.push_back("*");
      }
      i++;
    }
    return tokens;
  }
};

int main() {
  Solution so;
  so.calculate("3+2*2");
}

