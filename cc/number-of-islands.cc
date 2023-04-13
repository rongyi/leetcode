// https://www.lintcode.com/problem/number-of-distinct-islands/
#include "xxx.hpp"

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ret = 0;
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '0') {
          continue;
        }
        ret++;
        grid[i][j] = '0';
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
          auto [x, y] = q.front();
          q.pop();
          for (int d = 0; d < 4; d++) {
            auto nx = x + dirs[d][0];
            auto ny = y + dirs[d][1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '0') {
              continue;
            }
            grid[nx][ny] = '0';
            q.push({nx, ny});
          }
        }
      }
    }

    return ret;
  }
};
