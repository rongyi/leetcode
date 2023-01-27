// https://leetcode.com/problems/check-if-point-is-reachable/
#include "xxx.hpp"

class Solution {
public:
  bool isReachable(int targetX, int targetY) {
    auto g = gcd(targetX, targetY);

    return (g & (g - 1)) == 0;
  }
};
