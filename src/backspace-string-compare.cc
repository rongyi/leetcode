// https://leetcode.com/problems/backspace-string-compare/description/
#include "one.h"
class Solution {
public:
  bool backspaceCompare(string S, string T) {
    auto help = [](string &str) -> stack<char> {
      stack<char> ret;
      for (auto cur : str) {
        if (cur == '#') {
          if (!ret.empty()) {
            ret.pop();
          }
        } else {
          ret.push(cur);
        }
      }
      return ret;
    };

    auto shelp = help(S);
    auto thelp = help(T);
    while (!shelp.empty() && !thelp.empty()) {
      if (shelp.top() != thelp.top()) {
        return false;
      }
      shelp.pop();
      thelp.pop();
    }

    return shelp.empty() && thelp.empty();
  }
};
