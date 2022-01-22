// http://leetcode.com/problems/climbing-stairs/description/

#include "xxx.hpp"

class Solution {
public:
  int climbStairs(int n) {
    // fibonacci yo!
    int prev = 1;
    int cur = 1;
    int ret = 1;
    for (int i = 2; i <= n; ++i) {
      ret = prev + cur;
      prev = cur;
      cur = ret;
    }
    return ret;
  }
};
