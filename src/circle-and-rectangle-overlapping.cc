// http://leetcode.com/problems/circle-and-rectangle-overlapping/description/
#include "xxx.h"

class Solution {
public:
  bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1,
                    int x2, int y2) {
    // 圆心在矩形内, radius > 0
    if (x_center <= x2 && x_center >= x1 && y_center <= y2 && y_center >= y1) {
      return true;
    }
    //         |            |
    //    4    |    3       |  2
    //    ---------------------|-------
    //     5   |            |  1
    //         |            |
    //    -----------------------------
    //     6   |     7      |  8
    // case 1
    if (x_center > x2 && y_center <= y2 && y_center >= y1) {
      auto d = abs(x_center - x2);
      return radius >= d;
    } else if (x_center > x2 && y_center > y2) {
      // case 2
      auto dx = abs(x_center - x2);
      auto dy = abs(y_center - y2);
      auto d = dx * dx + dy * dy;
      return radius * radius >= d;
    } else if (x_center <= x2 && x_center >= x1 && y_center >= y2) {
      // case 3
      auto d = abs(y_center - y2);
      return radius >= d;
    } else if (x_center < x1 && y_center > y2) {
      auto dx = abs(x_center - x1);
      auto dy = abs(y_center - y2);
      auto d = dx * dx + dy * dy;
      return radius * radius >= d;
    } else if (x_center <= x1 && y_center <= y2 && y_center >= y1) {
      // case 5
      auto d = abs(x_center - x1);
      return radius >= d;
    } else if (x_center < x1 && y_center < y1) {
      // case 6
      auto dx = abs(x_center - x1);
      auto dy = abs(y_center - y1);
      auto d = dx * dx + dy * dy;
      return radius * radius >= d;
    } else if (x_center < x2 && x_center > x1 && y_center < y1) {
      // case 7
      auto d = abs(y_center - y1);
      return radius >= d;
    }
    // the last case 8
    auto dx = abs(x_center - x2);
    auto dy = abs(y_center - y1);
    auto d = dx * dx + dy * dy;
    return radius * radius >= d;
  }
};
