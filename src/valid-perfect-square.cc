// http://leetcode.com/problems/valid-perfect-square/description/
#include "simpleone.h"

class Solution {
public:
  bool isPerfectSquare(int num) {
    for (int i = 1; i <= num; i++) {
      if (i * i == num) {
        return true;
      } else if (i * i > num || i * i < 0) {
        return false;
      }
    }
  }
};
