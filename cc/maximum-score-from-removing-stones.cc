// http://leetcode.com/problems/maximum-score-from-removing-stones/description/
#include "xxx.h"

class Solution {
public:
  int maximumScore(int a, int b, int c) {
    // ensure the order a < b < c
    if (a > b) {
      return maximumScore(b, a, c);
    }
    if (b > c) {
      return maximumScore(a, c, b);
    }
    if (a + b <= c) {
      // 足够凑 (a, c), (b, c)
      // 一直凑到前面两个为0
      return a + b;
    }
    // 先把c凑到0
    // 然后剩下的搭配
    return c + (a + b - c) / 2;
  }
};
