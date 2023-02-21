// http://leetcode.com/problems/add-binary/description/
#include "xxx.hpp"

class Solution {
public:
  string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    ostringstream oss;
    int m = a.size();
    int n = b.size();

    int c = 0;
    for (int i = 0; i < max(m, n); i++) {
      int sum = c;
      if (i < m) {
        sum += (a[i] - '0');
      }
      if (i < n) {
        sum += (b[i] - '0');
      }
      oss << (sum % 2);
      c = sum / 2;
    }
    if (c) {
      oss << c;
    }
    string ret = oss.str();
    reverse(ret.begin(), ret.end());

    return ret;
  }
};
