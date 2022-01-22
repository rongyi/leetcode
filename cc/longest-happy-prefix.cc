// http://leetcode.com/problems/longest-happy-prefix/description/
#include "xxx.hpp"

class Solution {
public:
  string longestPrefix(string s) {
    const int mod = pow(10, 9) + 7;
    long h1 = 0;
    long h2 = 0;
    long mul = 1;
    int len = 0;
    for (int i = 0, j = s.size() - 1; j > 0; i++, --j) {
      int curi = s[i] - 'a';
      int curj = s[j] - 'a';
      h1 = (h1 * 26 + curi) % mod;
      h2 = (h2 + mul * curj) % mod;
      mul = (mul * 26) % mod;

      if (h1 == h2) {
        len = i + 1;
      }
    }
    return s.substr(0, len);
  }
};
