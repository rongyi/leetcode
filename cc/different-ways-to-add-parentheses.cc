// http://leetcode.com/problems/different-ways-to-add-parentheses/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> diffWaysToCompute(string input) {
    if (memo_.find(input) != memo_.end()) {
      return memo_[input];
    }
    vector<int> ret;
    for (int i = 0; i < input.size(); i++) {
      auto c = input[i];
      if (c == '+' || c == '-' || c == '*') {
        auto left = diffWaysToCompute(input.substr(0, i));
        // rest
        auto right = diffWaysToCompute(input.substr(i + 1));
        for (auto op1 : left) {
          for (auto op2 : right) {
            if (c == '+') {
              ret.push_back(op1 + op2);
            } else if (c == '-') {
              ret.push_back(op1 - op2);
            } else if (c == '*') {
              ret.push_back(op1 * op2);
            }
          }
        }
      }
    }
    if (ret.empty()) {
      ret.push_back(stoi(input));
    }
    memo_[input] = ret;
    return ret;
  }
private:
  unordered_map<string, vector<int>> memo_;
};
