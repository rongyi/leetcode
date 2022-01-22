// http://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/description/
#include "xxx.hpp"

class Solution {
public:
  // 喷的很惨
  int numPoints(vector<vector<int>> &points, int r) {
    int ret = 1;
    for (auto &p : points) {
      double alpha = 0.0;
      while (alpha < 360) {
        double cur_cos = cos(M_PI * alpha / 180);
        double cur_sin = sin(M_PI * alpha / 180);

        double cx = p[0] + (r * cur_cos);
        double cy = p[1] + (r * cur_sin);

        int cur_count = 0;
        for (auto &p2 : points) {
          double dist = sqrt(pow(p2[0] - cx, 2) + pow(p2[1] - cy, 2));
          if (dist - r < 0.01) {
            cur_count++;
          }
        }

        ret = max(ret, cur_count);
        alpha += 1;
      }
    }

    return ret;
  }
};
