// http://leetcode.com/problems/largest-triangle-area/description/
#include "xxx.h"

class Solution {
public:
  double largestTriangleArea(vector<vector<int>> &points) {
    double ret = 0.0;
    const int n = points.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          auto a = eucianDistance(points[i], points[j]);
          auto b = eucianDistance(points[j], points[k]);
          auto c = eucianDistance(points[i], points[k]);
          if (isValidTriangle(a, b, c)) {
            auto s = (a + b + c) / 2;
            ret = max(ret, sqrt(s * (s - a) * (s - b) * (s - c)));
          }
        }
      }
    }

    return ret;
  }

private:
  double eucianDistance(vector<int> &p1, vector<int> &p2) {
    int x = p1[0] - p2[0];
    int y = p1[1] - p2[1];
    return ::sqrt(x * x + y * y);
  }
  bool isValidTriangle(double a, double b, double c) {
    return (a + b) > c && (b + c) > a && (a + c) > b;
  }
};
