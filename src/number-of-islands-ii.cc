// https://www.lintcode.com/problem/number-of-islands-ii/description
#include "one.h"

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
  /**
   * @param n: An integer
   * @param m: An integer
   * @param operators: an array of point
   * @return: an integer array
   */
  vector<int> numIslands2(int m, int n, vector<Point> &operators) {
    vector<int> ret;
    int cur = 0;
    vector<int> boss(m * n, -1);
    vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (auto p : operators) {
      auto id = p.x * n + p.y;
      if (boss[id] == -1) {
        // my boss is myself
        boss[id] = id;
        ++cur;
      }
      for (auto dir: dirs) {
        auto nextx = p.x + dir[0];
        auto nexty = p.y + dir[1];
        auto nextid = n * nextx + nexty;
        if (nextx < 0 || nextx >= m || nexty < 0 || nexty >= n || boss[nextid] == -1) {
          continue;
        }
        auto p = findMyBoss(boss, nextid);
        auto q = findMyBoss(boss, id);
        if (p != q) {
          boss[p] = q;
          --cur;
        }
      }
      ret.push_back(cur);
    }

    return ret;
  }
private:
  int findMyBoss(vector<int> &boss, int id) {
    if (id == boss[id]) {
      return id;
    }
    return findMyBoss(boss, boss[id]);
  }
};
