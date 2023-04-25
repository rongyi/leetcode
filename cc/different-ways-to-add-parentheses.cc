// http://leetcode.com/problems/different-ways-to-add-parentheses/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> diffWaysToCompute(string s) {
    if (cache_.count(s)) {
      return cache_[s];
    }
    vector<int> ret;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
        auto l = diffWaysToCompute(s.substr(0, i));
        auto r = diffWaysToCompute(s.substr(i + 1));
        for (auto &op1 : l) {
          for (auto &op2 : r) {
            if (s[i] == '+') {
              ret.push_back(op1 + op2);
            } else if (s[i] == '-') {
              ret.push_back(op1 - op2);
            } else {
              ret.push_back(op1 * op2);
            }
          }
        }
      }
    }
    // just number, no operator contained
    if (ret.empty()) {
      ret.push_back(stoi(s));
    }

    cache_[s] = ret;
    return ret;
  }

private:
  map<string, vector<int>> cache_;
};
