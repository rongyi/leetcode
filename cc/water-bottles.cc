// http://leetcode.com/problems/water-bottles/description/
#include "xxx.hpp"

class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    // drink all
    int ret = numBottles;

    // we have numBottles empty bottles
    while (numBottles >= numExchange) {
      int ex_bottle = numBottles / numExchange;
      // we drink it
      ret += numBottles / numExchange;
      numBottles = numBottles / numExchange + numBottles % numExchange;
      // drink the ex bottle and we have more empty bottles
    }

    return ret;
  }
};
