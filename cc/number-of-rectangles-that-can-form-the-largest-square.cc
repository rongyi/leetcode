// http://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/description/
#include "xxx.h"

class Solution {
public:
  int countGoodRectangles(vector<vector<int>> &rectangles) {
    map<int, int> count;
    int ms = 0;
    for (auto &p : rectangles) {
      auto s = min(p[0], p[1]);
      count[s]++;
      ms = max(ms, s);
    }

    return count[ms];
  }
};
