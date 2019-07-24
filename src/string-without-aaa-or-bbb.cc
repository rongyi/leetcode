// http://leetcode.com/problems/string-without-aaa-or-bbb/description/
#include "xxx.h"

class Solution {
public:
  string strWithout3a3b(int A, int B) {
    return recur(A, B, 'a', 'b');
  }
  string recur(int A, int B, char a, char b) {
    if (B > A) {
      return recur(B, A, b, a);
    }
    if (B == 0) {
      return string(A, a);
    }
    int rep = 1;
    if (A > B) {
      rep = 2;
    }
    return string(rep, a) + b + recur(A - rep, B- 1, a, b);
  }
};
