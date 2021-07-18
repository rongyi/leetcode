// http://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/description/
#include "xxx.h"

class Solution {
public:
  int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
    int min_distance = numeric_limits<int>::max();
    int ret = -1;
    for (int i = 0; i < points.size(); ++i) {
      if (points[i][0] != x && points[i][1] != y) {
        continue;
      }
      int cur_distance = abs(points[i][0] - x) + abs(points[i][1] - y);
      if (cur_distance < min_distance) {
        min_distance = cur_distance;
        ret = i;
      }
    }

    return ret;
  }
};
