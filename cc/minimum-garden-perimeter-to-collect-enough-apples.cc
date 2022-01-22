// https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/
#include "xxx.hpp"

class Solution {
public:
  long long minimumPerimeter(long long neededApples) {
    long long i = 1;
    for (; neededApples > 0; ++i) {
      neededApples -= 3 * i * 4;           // i * 4 + 2 * i * 4
      neededApples -= 3 * i * (i - 1) * 4; // (i+1, i+2, ... 2*i - 1) * 8
    }
    return (i - 1) * 8;
  }
};
