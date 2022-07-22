// https://leetcode.com/problems/count-number-of-ways-to-place-houses/
#include "xxx.hpp"

class Solution {
public:
  int countHousePlacements(int n) {
    int space = 1;
    int house = 1;
    long long total = space + house;

    for (int i = 2; i <= n; ++i) {
      house = space;
      space = total;
      total = (house + space) % int(1e9 + 7);
    }

    return (total * total) % int(1e9 + 7);
  }
};
