// http://leetcode.com/problems/sum-of-square-numbers/description/
#include "xxx.h"

class Solution {
public:
  bool judgeSquareSum(int c) {
    if (c < 0) {
      return false;
    }
    long long left = 0;
    long long right = (int)sqrt(c);
    while (left <= right) {
      long long cur = left * left + right * right;
      if (cur == c) {
        return true;
      } else if (cur < c) {
        left++;
      } else {
        right--;
      }
    }
    return false;
  }
};
