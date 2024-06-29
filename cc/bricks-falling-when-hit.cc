// https://leetcode.com/problems/bricks-falling-when-hit/description/
#include "xxx.hpp"
#include <vector>

class Solution {
public:
  vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
    int sz = hits.size();
    vector<int> ret(sz, 0);
    // hit them all first
    for (auto &hit : hits) {
      int x = hit[0];
      int y = hit[1];
      // real hit
      if (grid[x][y] == 1) {
        grid[x][y] = 0;
      } else {
        // hit in the air, mark as no op
        grid[x][y] = -1;
      }
    }
    for (int j = 0; j < grid[0].size(); j++) {
      dfs(grid, 0, j);
    }
    for (int i = sz - 1; i >= 0; i--) {
      int x = hits[i][0];
      int y = hits[i][1];
      // no op action
      if (grid[x][y] == -1) {
        continue;
      }
      grid[x][y] = 1;
      bool need_recount = x == 0;
      // see neighbor can find chain to roof
      if (!need_recount) {
        for (auto &d : dir_) {
          int nx = x + d[0];
          int ny = y + d[1];
          if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) {
            continue;
          }
          if (grid[nx][ny] == 2) {
            need_recount = true;
            break;
          }
        }
      }
      if (need_recount) {
        ret[i] = dfs(grid, x, y) - 1;
      }
    }

    return ret;
  }

  int dfs(vector<vector<int>> &grid, int x, int y) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
      return 0;
    }
    if (grid[x][y] != 1) {
      return 0;
    }
    // means can be chained up to ceil
    grid[x][y] = 2;
    int ret = 1;
    for (auto &d : dir_) {
      int nx = x + d[0];
      int ny = y + d[1];
      // the hit node is we added, wee don't count them
      ret += dfs(grid, nx, ny);
    }

    return ret;
  }

private:
  vector<vector<int>> dir_{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};
