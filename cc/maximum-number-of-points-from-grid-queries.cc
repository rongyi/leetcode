// https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/
#include "xxx.hpp"

class Solution {
public:
  vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
    int m = grid.size();
    int n = grid[0].size();
    int qsz = queries.size();

    // {val, pos}
    vector<pair<int, int>> qwithidx;
    for (int i = 0; i < qsz; ++i) {
      qwithidx.push_back({queries[i], i});
    }
    sort(qwithidx.begin(), qwithidx.end());

    vector<vector<int>> visited(m, vector<int>(n, 0));
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>
        q;
    q.push({grid[0][0], 0, 0});
    int valid_cnt = 0;

    vector<int> ret(qsz, 0);
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (auto &qry : qwithidx) {
      while (!q.empty() && abs(q.top()[0]) < qry.first) {
        auto [_, x, y] = q.top();
        q.pop();

        if (visited[x][y]) {
          continue;
        }
        visited[x][y] = 1;
        valid_cnt++;

        for (int i = 0; i < dirs.size(); ++i) {
          auto nextx = x + dirs[i][0];
          auto nexty = y + dirs[i][1];
          if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n &&
              !visited[nextx][nexty]) {
            q.push({grid[nextx][nexty], nextx, nexty});
          }
        }
      }

      ret[qry.second] = valid_cnt;
    }

    return ret;
  }
};
