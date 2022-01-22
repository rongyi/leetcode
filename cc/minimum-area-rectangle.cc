// http://leetcode.com/problems/minimum-area-rectangle/description/
#include "xxx.hpp"

class Solution {
public:
  int minAreaRect(vector<vector<int>> &points) {
    set<pair<int, int>> ps;
    // 所有x相等的坐标
    unordered_map<int, unordered_set<int>> xequals;
    // 所有y相等的坐标
    unordered_map<int, unordered_set<int>> yequals;
    long long ret = numeric_limits<long long>::max();

    for (auto &p : points) {
      ps.insert({p[0], p[1]});
      xequals[p[0]].insert(p[1]);
      yequals[p[1]].insert(p[0]);
    }

    // 关系如下
    //   (x, y2)-------------- (curx,  y2)
    //      |                  |
    //   (x, y1) -------------(curx, y1)
    for (auto xkv : xequals) {
      if (xkv.second.size() < 2) {
        continue;
      }
      int x = xkv.first;
      for (auto y1 : xkv.second) {
        for (auto y2 : xkv.second) {
          if (y1 == y2) {
            continue;
          }
          // 有两个坐标(x, y1) (x, y2)
          // 拼不起来，只有一个点
          if (yequals[y1].size() < 2 || yequals[y2].size() < 2) {
            continue;
          }
          // 随便取一个
          for (auto curx : yequals[y1]) {
            if (curx == x) {
              continue;
            }
            // 那么第四个点的坐标就是 (curx, y2)
            // 拼不成矩形
            if (ps.find({curx, y2}) == ps.end()) {
              continue;
            }
            long long cur_area = abs(curx - x) * abs(y2 - y1);
            ret = min(ret, cur_area);
          }
        }
      }
    }
    if (ret == numeric_limits<long long>::max()) {
      return 0;
    }
    return ret;
  }
};
