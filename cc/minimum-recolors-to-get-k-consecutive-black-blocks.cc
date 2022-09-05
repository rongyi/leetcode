// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
#include "xxx.hpp"

class Solution {
public:
  int minimumRecolors(string blocks, int k) {
    int sz = blocks.size();
    int change = 0;
    int ret = numeric_limits<int>::max();
    for (int i = 0; i < sz; ++i) {
      if (blocks[i] == 'W') {
        change++;
      }
      if (i >= k) {
        if (blocks[i - k] == 'W') {
          change--;
        }
      }
      if (i + 1 >= k) {
        ret = min(ret, change);
      }
    }

    return ret;
  }
};
