// http://leetcode.com/problems/coordinate-with-maximum-network-quality/description/
#include "xxx.h"

class Solution {
public:
  vector<int> bestCoordinate(vector<vector<int>> &towers, int radius) {
    sort(towers.begin(), towers.end());
    int curid = 0;
    int maxq = 0;
    int maxx = 0;
    int maxy = 0;
    deque<int> range;
    for (int curx = towers.front()[0]; curx <= towers.back()[0]; ++curx) {
      while (curid < towers.size() && curx + radius >= towers[curid][0]) {
        range.push_back(curid++);
      }
      while (!range.empty() && towers[range.front()][0] < curx - radius) {
        range.pop_front();
      }

      for (int cury = 0; cury <= 50; ++cury) {
        int curq = 0;
        for (auto id : range) {
          if (towers[id][1] < cury - radius || towers[id][1] > cury + radius) {
            continue;
          }
          auto dd = (towers[id][0] - curx) * (towers[id][0] - curx) +
                    (towers[id][1] - cury) * (towers[id][1] - cury);
          if (dd <= radius * radius) {
            curq += towers[id][2] / (1 + sqrt(dd));
          }
          if (maxq < curq) {
            maxq = curq;
            maxx = curx;
            maxy = cury;
          }
        }
      }
    }

    return {maxx, maxy};
  }
};
