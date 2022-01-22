// http://leetcode.com/problems/min-cost-to-connect-all-points/description/
#include "xxx.hpp"

class Solution {
public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    int n = points.size();
    int ret = 0;
    vector<int> ds(n, -1);
    vector<array<int, 3>> arr;
    for (auto i = 0; i < n; ++i) {
      for (auto j = i + 1; j < n; ++j) {
        auto md =
            abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        arr.push_back({md, i, j});
      }
    }
    make_heap(arr.begin(), arr.end(), greater<array<int, 3>>());
    while (!arr.empty()) {
      pop_heap(arr.begin(), arr.end(), greater<array<int, 3>>());
      auto last = arr.back();
      auto dist = last[0];
      auto i = last[1];
      auto j = last[2];
      arr.pop_back();

      i = find(ds, i);
      j = find(ds, j);
      if (i != j) {
        ret += dist;
        // 连起来
        ds[i] += ds[j];
        ds[j] = i;
        // union find 如果这里不理解请参考:
        // remove-max-number-of-edges-to-keep-graph-fully-traversable.cc:28
        if (ds[i] == -n) {
          break;
        }
      }
    }

    return ret;
  }

private:
  int find(vector<int> &ds, int i) {
    return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
  }
};
