// https://leetcode.com/problems/add-minimum-number-of-rungs/
#include "xxx.h"
class Solution {
public:
  int addRungs(vector<int> &rungs, int dist) {
    int ret = 0;
    int sz = rungs.size();
    // you are currently on the floor!
    int prev = 0;
    for (int i = 0; i < sz; ++i) {
      int diff = rungs[i] - prev;
      prev = rungs[i];
      if (diff <= dist) {
        continue;
      }
      // why minus one?
      // one rung can get you dist
      // e.g. 4 distance need one rung
      ret += (diff - 1) / dist;
    }

    return ret;
  }
};
