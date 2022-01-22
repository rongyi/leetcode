// http://leetcode.com/problems/plus-one/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    const int n = digits.size();
    vector<int> ret;
    if (n == 0) {
      return ret;
    }
    int carry = 0;
    // plus one
    digits[n - 1] += 1;

    for (int i = n - 1; i >= 0; i--) {
      auto sum = digits[i] + carry;
      carry = sum / 10;
      sum %= 10;
      ret.push_back(sum);
    }
    if (carry > 0) {
      ret.push_back(carry);
    }
    reverse(ret.begin(), ret.end());

    return ret;
  }
};
