// http://leetcode.com/problems/add-strings/description/
#include "xxx.hpp"

class Solution {
public:
  string addStrings(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int carry = 0;
    const int m = num1.size();
    const int n = num2.size();

    stringstream ss;
    for (int i = 0; i < m || i < n || carry; ++i) {
      int sum = carry;
      if (i < m) {
        sum += num1[i] - '0';
      }
      if (i < n) {
        sum += num2[i] - '0';
      }
      ss << sum % 10;

      carry = sum / 10;
    }

    string ret = ss.str();
    reverse(ret.begin(), ret.end());

    return ret;
  }
};
