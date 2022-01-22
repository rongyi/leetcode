// http://leetcode.com/problems/height-checker/description/
#include "xxx.hpp"

class Solution {
public:
  int heightChecker(vector<int> &heights) {
    int ret = 0;
    vector<int> cp = heights;
    sort(begin(cp), end(cp));
    for (int i = 0; i < heights.size(); ++i) {
      if (cp[i] != heights[i]) {
        ++ret;
      }
    }

    return ret;
  }
};
