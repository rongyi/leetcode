// https://leetcode.com/problems/basic-calculator/description/
#include "one.h"
class Solution {
public:
  // assume the give expression is always valid, yeah
  int calculate(string s) {
    auto tks = tokenize(s);
    const int n = tks.size();
    auto ret = 0;
    for (int i = 0; i < n; ++i) {
      if (tks[i] == "+" || tks[i] == "-") {
        auto op1 = stoi(tks[i - 1]);
        auto op2 = stoi(tks[i + 1]);
        if (tks[i] == "+") {
          ret += (op1 + op2);
        } else {
          ret += op1 - op2;
        }
        i += 2;
      } else {
        ++i;
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
      if (s[j] == ' ' || s[j] == '+' || s[j] == '-') {
        if (in_digit) {
          // not digit now
          in_digit = false;
          ret.push_back(s.substr(start, j - start));
        }
        // not space, then must be + or -
        if (s[j] != ' ') {
          ret.push_back({s[j]});
        }
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  string input{"123      +    3"};
  auto tks = so.tokenize(input);
  for (auto t : tks) {
    cout << t << endl;
  }
  auto ret = so.calculate(input);
  cout << ret << endl;
}
