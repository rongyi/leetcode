// https://leetcode.com/problems/max-points-on-a-line/
#include "xxx.hpp"

class Solution {
public:
  int maxPoints(vector<vector<int>> &points) {
    int sz = points.size();
    if (sz < 3) {
      return sz;
    }
    int ret = 1;
    for (int i = 0; i < sz; i++) {
      map<pair<int, int>, int> line;
      int x1 = points[i][0];
      int y1 = points[i][1];
      for (int j = i + 1; j < sz; j++) {
        int x2 = points[j][0];
        int y2 = points[j][1];
        int dx = x1 - x2;
        int dy = y1 - y2;
        int d = __gcd(dx, dy);
        line[{dx / d, dy / d}]++;
      }
      for (auto &kv : line) {
        ret = max(ret, kv.second + 1);
      }
    }

    return ret;
  }
};
