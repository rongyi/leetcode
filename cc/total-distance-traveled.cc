// https://leetcode.com/problems/total-distance-traveled/
#include "xxx.hpp"

class Solution {
public:
  int distanceTraveled(int mainTank, int additionalTank) {
    int used_fuel = 0;
    while (mainTank >= 5) {
      mainTank -= 5;
      used_fuel += 5;
      if (additionalTank >= 1) {
        mainTank += 1;
        additionalTank--;
      }
    }
    used_fuel += mainTank;

    return used_fuel * 10;
  }
};
