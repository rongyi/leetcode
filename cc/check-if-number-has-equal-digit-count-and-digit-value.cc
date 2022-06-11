// https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/
#include "xxx.hpp"

class Solution {
public:
  bool digitCount(string num) {
    vector<int> count(10, 0);
    for (auto c : num) {
      count[c - '0']++;
    }

    for (int i = 0; i < num.size(); ++i) {
      // still don't get the problem, but the check is this:
      if ((num[i] - '0') != count[i]) {
        return false;
      }
    }

    return true;
  }
};
