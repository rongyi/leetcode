// http://leetcode.com/problems/koko-eating-bananas/description/
#include "xxx.hpp"

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int H) {
    int l = 1;
    int r = 1000000000;
    while (l < r) {
      int m = l + (r - l) / 2;
      int total = 0;
      for (auto p : piles) {
        total += (p + m - 1) / m;
      }
      // 说明吃的慢了，要加快
      if (total > H) {
        l = m + 1;
      } else {
        // 说明吃的快了，要放慢
        r = m;
      }
    }
    return l;
  }
};
