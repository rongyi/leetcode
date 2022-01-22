// http://leetcode.com/problems/play-with-chips/description/
#include "xxx.hpp"

class Solution {
public:
  int minCostToMoveChips(vector<int> &chips) {
    int sum[2] ={};
    for (auto c : chips) {
      ++sum[c % 2];
    }
    return min(sum[0], sum[1]);
  }
};
