// http://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    // tomatoSlices will always be even number
    // cheeseSlices will never > tomatoSlices / 2
    if (tomatoSlices % 2 || cheeseSlices > tomatoSlices / 2) {
      return {};
    }
    // 2x + 4y = tomatoSlices
    // x + y = cheeseSlices
    auto x = 2 * cheeseSlices - tomatoSlices / 2;
    auto y = (tomatoSlices / 2) - cheeseSlices;
    if (x < 0 || y < 0) {
      return {};
    }
    return {y, x};
  }
};
