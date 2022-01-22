// http://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/
#include "xxx.hpp"

class Solution {
public:
  int minOperations(string s) {
    int ret = s.size();
    // keep first unchanged, and flip in orders
    int count = 0;
    int expect = 1 - (s[0] - '0');
    for (int i = 1; i < s.size(); ++i) {
      int cur = s[i] - '0';
      if (cur != expect) {
        count++;
      }
      expect ^= 1;
    }
    ret = min(ret, count);
    count = 1;
    // flip first and change indorders
    expect = s[0] - '0';
    for (int i = 1; i < s.size(); ++i) {
      int cur = s[i] - '0';
      if (cur != expect) {
        count++;
      }
      expect ^= 1;
    }

    // select the min
    return min(ret, count);
  }
};
