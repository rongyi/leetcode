// http://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/
#include "xxx.hpp"

class Solution {
public:
  int maxCoins(vector<int> &piles) {
    const int n = piles.size();
    sort(piles.begin(), piles.end(), std::greater<int>());
    int ret = 0;
    for (int i = 0; i < n / 3; ++i) {
      ret += piles[i * 2 + 1];
    }
    return ret;
  }
};
