// http://leetcode.com/problems/maximum-units-on-a-truck/description/
#include "xxx.h"

class Solution {
public:
  // 盒子数量固定，所以优先盒子里零件最多的那个上
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(),
         [](auto &l, auto &r) { return l[1] > r[1]; });

    int ret = 0;
    for (auto &bt : boxTypes) {
      auto fit = min(truckSize, bt[0]);
      ret += fit * bt[1];
      truckSize -= fit;
      if (truckSize == 0) {
        break;
      }
    }
    return ret;
  }
};
