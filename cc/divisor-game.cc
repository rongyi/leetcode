// http://leetcode.com/problems/divisor-game/description/
#include "xxx.hpp"

class Solution {
public:
  // 喷的很惨
  bool divisorGame(int N) {
    return (N & 1) == 0;
  }
};
