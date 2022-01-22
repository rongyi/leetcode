// http://leetcode.com/problems/broken-calculator/description/
#include "xxx.hpp"

class Solution {
public:
  // X ==> Y
  // double x
  // or minus 1
  int brokenCalc(int X, int Y) {
    // So we check only the last bit of Y, since doubling and -1 can only alter (directly) one bit.

    // if last bit of Y is 0, the last operation must be doubling, we trace back to Y/2
    // if last bit of Y is 1, the last operation must be decrement, we trace back to Y+1
    if (X >= Y) {
      return X - Y;
    }
    if (Y & 1) {
      return 1 + brokenCalc(X, Y + 1);
    }

    return 1 + brokenCalc(X, Y / 2);
  }
};
