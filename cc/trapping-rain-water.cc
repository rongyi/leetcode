// http://leetcode.com/problems/trapping-rain-water/description/
#include "xxx.hpp"

class Solution {
public:
  int trap(vector<int> &height) {
    int sz = height.size();
    vector<int> l(sz, 0);
    vector<int> r(sz, 0);

    int val = 0;
    for (int i = 0; i < sz - 1; i++) {
      val = max(val, height[i]);
      l[i + 1] = val;
    }
    val = 0;
    for (int i = sz - 1; i > 0; i--) {
      val = max(val, height[i]);
      r[i - 1] = val;
    }
    int acc = 0;
    for (int i = 1; i < sz - 1; i++) {
      int diff = min(l[i], r[i]) - height[i];
      if (diff > 0) {
        acc += diff;
      }
    }

    return acc;
  }
};

