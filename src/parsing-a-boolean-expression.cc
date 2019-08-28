// http://leetcode.com/problems/parsing-a-boolean-expression/description/
#include "xxx.h"

class Solution {
public:
  bool parseBoolExpr(string expression) {
    auto first = expression[0];
    if (first == '!') {
      return parseNot(expression);
    } else if (first == '|') {
      return parseOr(expression);
    } else if (first == '&') {
      return parseAnd(expression);
    }
    return parseAtom(expression);
  }

private:
  bool parseOr(string str) {
    // ignore !(
    int i = 2;
    while (i < str.size()) {
      auto cur = curStatment(str, i, i);
      bool value_cur = parseBoolExpr(cur);
      // lazy evaluation
      if (value_cur) {
        return true;
      }
      // jump over ','
      if (i < str.size()) {
        i++;
      }
    }

    return false;
  }
  bool parseAnd(string str) {
    int i = 2;
    while (i < str.size()) {
      auto cur = curStatment(str, i, i);
      bool value_cur = parseBoolExpr(cur);
      // lazy evaluation
      if (!value_cur) {
        return false;
      }
      // jump over ','
      if (i < str.size()) {
        ++i;
      }
    }

    return true;
  }
  bool parseNot(string str) {
    int i = 2;
    auto cur = curStatment(str, i, i);

    return !parseBoolExpr(cur);
  }
  bool parseAtom(string s) {
    if (s == "t") {
      return true;
    }
    return false;
  }
  // contain '()' or atom, both considered
  string curStatment(string raw, int cur, int &next_valid) {
    // atom case
    if (raw[cur] == 'f' || raw[cur] == 't') {
      ++next_valid;
      return string{raw[cur]};
    }

    stack<int> stk;
    int end = -1;
    for (auto i = cur; i < raw.size(); ++i) {
      if (raw[i] == '(') {
        stk.push(i);
      } else if (raw[i] == ')') {
        stk.pop();
        end = i;
        // match the outer most end
        if (stk.empty()) {
          break;
        }
      }
    }
    next_valid = end + 1;

    return raw.substr(cur, next_valid - cur);
  }
};

int main() {
  Solution so;
  auto ret = so.parseBoolExpr("|(&(t,f,t),!(t))");
  cout << ret << endl;
}
