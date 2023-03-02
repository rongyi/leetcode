// http://leetcode.com/problems/largest-rectangle-in-histogram/description/
#include "xxx.hpp"

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    heights.push_back(-1);

    int sz = heights.size();
    int ret = 0;
    vector<int> stk;
    for (int i = 0; i < sz;) {
      if (stk.empty() || heights[stk.back()] < heights[i]) {
        stk.push_back(i);
        i++;
      } else {
        int idx = stk.back();
        stk.pop_back();
        if (stk.empty()) {
          ret = max(ret, i * heights[idx]);
        } else {
          ret = max(ret, (i - stk.back() - 1) * heights[idx]);
        }
      }
    }
    return ret;
  }
};
