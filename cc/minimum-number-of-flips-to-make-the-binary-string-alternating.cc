// http://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/
#include "xxx.h"

class Solution {
public:
  int minFlips(string s) {
    int sz = s.size();
    s += s;
    // 1010
    string s1;
    // 0101
    string s2;
    for (int i = 0; i < s.size(); ++i) {
      if (i & 1) {
        s1.push_back('0');
        s2.push_back('1');
      } else {
        s1.push_back('1');
        s2.push_back('0');
      }
    }

    int ret = numeric_limits<int>::max();
    int ch1 = 0;
    int ch2 = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != s1[i]) {
        ch1++;
      }
      if (s[i] != s2[i]) {
        ch2++;
      }
      // the first window ending at sz - 1
      // after this we cut the tail
      if (i >= sz) {
        if (s[i - sz] != s1[i - sz]) {
          --ch1;
        }
        if (s[i - sz] != s2[i - sz]) {
          --ch2;
        }
      }
      // the first fully window ending at sz - 1
      if (i >= sz - 1) {
        ret = min({ret, ch1, ch2});
      }
    }

    return ret;
  }
};
