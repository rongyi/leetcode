// http://leetcode.com/problems/map-of-highest-peak/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
    using pi = pair<int, int>;
    const int m = isWater.size();
    const int n = isWater[0].size();
    vector<vector<int>> is_visited(m, vector<int>(n, -1));
    queue<pi> q;
    int cur_height = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (isWater[i][j] == 1) {
          q.push({i, j});
          isWater[i][j] = cur_height;
          is_visited[i][j] = 1;
        }
      }
    }
    vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!q.empty()) {
      ++cur_height;
      const int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        auto cur = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
          auto nx = cur.first + dir[d][0];
          auto ny = cur.second + dir[d][1];
          if (nx >= m || nx < 0 || ny >= n || ny < 0 ||
              is_visited[nx][ny] == 1) {
            continue;
          }
          is_visited[nx][ny] = 1;
          isWater[nx][ny] = cur_height;

          q.push({nx, ny});
        }
      }
    }

    return isWater;
  }
};
