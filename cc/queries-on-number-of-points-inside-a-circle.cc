// http://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/description/
#include "xxx.h"

class Solution {
public:
  vector<int> countPoints(vector<vector<int>> &points,
                          vector<vector<int>> &queries) {
    vector<int> ret;

    for (auto &q : queries) {
      int cur_count = 0;
      for (auto &p : points) {
        auto d = twoPointDistance(q[0], q[1], p[0], p[1]);
        if (d <= (long long)q[2] * q[2]) {
          cur_count++;
        }
      }
      ret.push_back(cur_count);
    }

    return ret;
  }

private:
  long long twoPointDistance(long long x1, long long y1, long long x2,
                             long long y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  }
};
