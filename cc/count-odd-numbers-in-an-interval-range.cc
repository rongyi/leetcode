// http://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/
#include "xxx.hpp"

class Solution {
public:
  int countOdds(int low, int high) {
    if (low & 1) {
      return (high - low + 2) / 2; // (high - low + 1) + 1
    }
    return (high - low + 1) / 2;
  }
};
