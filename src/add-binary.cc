// http://leetcode.com/problems/add-binary/description/
#include "one.h"

class Solution {
public:
  string addBinary(string a, string b) {
    const int m = a.size();
    const int n = b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<char> ret;
    int carry = 0;
    int i = 0;
    for (i = 0; i < min(m, n); i++) {
      auto sum = carry + (a[i] - '0') + (b[i] - '0');
      carry = sum / 2;
      sum %= 2;
      ret.push_back(sum + '0');
    }
    for (; i < m; ++i) {
      auto sum = carry + (a[i] - '0');
      carry = sum / 2;
      sum %= 2;
      ret.push_back(sum + '0');
    }
    for (; i < n; ++i) {
      auto sum = carry + (b[i] - '0');
      carry = sum / 2;
      sum %= 2;
      ret.push_back(sum + '0');
    }
    if (carry) {
      ret.push_back('1');
    }
    reverse(ret.begin(), ret.end());
    return string(ret.begin(), ret.end());
  }
};
