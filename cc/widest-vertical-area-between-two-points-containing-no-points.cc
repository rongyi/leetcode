// http://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/
#include "xxx.h"

class Solution {
public:
  // 喷的很惨
  // 题目真的是莫名其妙，算间隔就好了
  int maxWidthOfVerticalArea(vector<vector<int>> &points) {
    sort(points.begin(), points.end());
    int ret = 0;
    for (int i = 1; i < points.size(); ++i) {
      ret = max(ret, points[i][0] - points[i - 1][0]);
    }

    return ret;
  }
};
