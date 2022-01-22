// http://leetcode.com/problems/minimum-time-visiting-all-points/description/
#include "xxx.hpp"

class Solution {
public:
  int minTimeToVisitAllPoints(vector<vector<int>> &points) {
    const int n = points.size();
    int ret = 0;
    for (int i = 1; i < n; ++i) {
      //真是不可思议，竟然就是这个答案
      ret += max(abs(points[i][0] - points[i - 1][0]),
                 abs(points[i][1] - points[i - 1][1]));
    }
    return ret;
  }
};
