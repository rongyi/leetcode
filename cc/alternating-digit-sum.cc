// https://leetcode.com/problems/alternating-digit-sum/
#include "xxx.hpp"

class Solution {
public:
  int alternateDigitSum(int n) {
    int sign = 1;
    int sum = 0;
    string s = to_string(n);
    for (int i = 0; i < s.size(); ++i) {
      sum += (s[i] - '0') * sign;
      sign *= -1;
    }
    return sum;
  }
};
