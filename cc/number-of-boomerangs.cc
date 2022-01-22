// http://leetcode.com/problems/number-of-boomerangs/description/
#include "xxx.hpp"

class Solution {
public:
  int numberOfBoomerangsV1(vector<pair<int, int>> &points) {
    int ret = 0;

    for (auto &p : points) {
      unordered_map<double, int> count(points.size());
      for (auto &q : points) {
        ret += 2 * count[::hypot(p.first - q.first, p.second - q.second)]++;
      }
    }

    return ret;
  }

  int numberOfBoomerangs(vector<pair<int, int>> &points) {
    const int n = points.size();

    unordered_map<int, int> count;
    int ret{};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) {
          continue;
        }
        auto x = points[i].first - points[j].first;
        auto y = points[i].second - points[j].second;
        count[x * x + y * y]++;
      }
      for (auto kv : count) {
        if (kv.second > 1) {
          /*
           * for all the groups of points,
           * number of ways to select 2 from n =
           * nP2 = n!/(n - 2)! = n * (n - 1)
           */
          ret += kv.second * (kv.second - 1);
        }
      }

      count.clear();
    }

    return ret;
  }
};
