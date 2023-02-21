// http://leetcode.com/problems/climbing-stairs/description/

#include "xxx.hpp"

class Solution {
public:
  int climbStairs(int n) {
    // f(n) = f(n - 1) + f(n - 2)
    int prev = 1;
    int cur = 1;
    int sum = cur;
    for (int i = 2; i <= n; i++) {
      sum = prev + cur;
      prev = cur;
      cur = sum;
    }

    return sum;
  }
};
