// http://leetcode.com/problems/determine-if-string-halves-are-alike/description/
#include "xxx.hpp"

class Solution {
public:
  bool halvesAreAlike(string s) {
    const int n = s.size() / 2;
    // r not included
    auto count = [](string &s, int l, int r) {
      int ret = 0;
      for (int i = l; i < r; ++i) {
        if (s[i] == 'a' || s[i] == 'o' || s[i] == 'e' || s[i] == 'i' ||
            s[i] == 'u' || s[i] == 'A' || s[i] == 'O' || s[i] == 'E' ||
            s[i] == 'I' || s[i] == 'U') {
          ret++;
        }
      }
      return ret;
    };

    return count(s, 0, n) == count(s, n, 2 * n);
  }
};
