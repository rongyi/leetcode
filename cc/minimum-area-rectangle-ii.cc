// http://leetcode.com/problems/minimum-area-rectangle-ii/description/
#include "xxx.hpp"

class Solution {
public:
  // 编程角度讲，这道题没什么意思
  double minAreaFreeRect(vector<vector<int>> &ps, size_t res = 0) {
    unordered_map<size_t, vector<vector<int>>> centers;
    for (auto i = 0; i < ps.size(); ++i)
      for (auto j = i + 1; j < ps.size(); ++j) {
        auto center =
            ((size_t)(ps[i][0] + ps[j][0]) << 16) + ps[i][1] + ps[j][1];
        centers[center].push_back({ps[i][0], ps[i][1], ps[j][0], ps[j][1]});
      }
    for (auto kv : centers) {
      for (auto i = 0; i < kv.second.size(); ++i) {
        for (auto j = i + 1; j < kv.second.size(); ++j) {
          auto &p1 = kv.second[i], &p2 = kv.second[j];
          if ((p1[0] - p2[0]) * (p1[0] - p2[2]) + (p1[1] - p2[1]) * (p1[1] - p2[3]) == 0) {
            auto area = distance(p1[0], p1[1], p2[0], p2[1]) *
                        distance(p1[0], p1[1], p2[2], p2[3]);
            if (res == 0 || res > area) {
              res = area;
            }
          }
        }
      }
    }
    return sqrt(res);
  }

private:
  size_t distance(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  }
};
