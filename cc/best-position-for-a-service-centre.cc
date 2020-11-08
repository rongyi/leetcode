// http://leetcode.com/problems/best-position-for-a-service-centre/description/
#include "xxx.h"

class Solution {
public:
  // 喷的很惨
  // 三分查找方法
  double getMinDistSum(vector<vector<int>> &positions) {
    double x1 = 0;
    double x2 = 100;
    double y1 = 0;
    double y2 = 100;
    double pre_min = 1e9;
    double cur_min = 0;
    double eps = 5e-6;
    while (abs(pre_min - cur_min) > eps || (x2 - x1) > eps || (y2 - y1) > eps) {
      pre_min = cur_min;
      cur_min = zoomin(positions, x1, x2, y1, y2);
    }

    return pre_min;
  }

private:
  double zoomin(const vector<vector<int>> &positions, double &x1, double &x2,
                double &y1, double &y2) {
    const int n = 3;
    const double dx = (x2 - x1) / n;
    const double dy = (y2 - y1) / n;
    double min_dis = 1e9;
    double xmin = 0;
    double ymin = 0;

    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        double newposx = x1 + dx * i;
        double newposy = y1 + dy * j;
        double cur_dis = sum_dis(newposx, newposy, positions);
        if (cur_dis < min_dis) {
          xmin = newposx;
          ymin = newposy;
          min_dis = cur_dis;
        }
      }
    }

    x1 = xmin - dx;
    x2 = xmin + dx;
    y1 = ymin - dy;
    y2 = ymin + dy;

    return min_dis;
  }

  double sum_dis(double x, double y, const vector<vector<int>> &positions) {
    double ret = 0;

    for (auto &v : positions) {
      ret += sqrt(pow(x - v[0], 2) + pow(y - v[1], 2));
    }

    return ret;
  }
};
