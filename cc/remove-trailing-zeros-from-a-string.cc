// https://leetcode.com/problems/remove-trailing-zeros-from-a-string/
#include "xxx.hpp"

class Solution {
public:
  string removeTrailingZeros(string num) {
    while (!num.empty() && num.back() == '0') {
      num.pop_back();
    }
    return num;
  }
};
