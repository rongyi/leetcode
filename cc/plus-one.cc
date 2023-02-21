// http://leetcode.com/problems/plus-one/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int sz = digits.size();
    int carry = 1;
    for (int i = sz - 1; i >= 0; --i) {
      digits[i] += carry;
      if (digits[i] <= 9) {
        carry = 0;
        break;
      } else {
        carry = 1;
        digits[i] %= 10;
      }
    }
    if (carry) {
      digits.insert(digits.begin(), 1);
    }

    return digits;
  }
};
