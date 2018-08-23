// https://leetcode.com/problems/bricks-falling-when-hit/description/
#include "one.h"

class Solution {
public:
  vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
    row_num = grid.size(), col_num = grid[0].size();
    vector<int> ret;
    for (auto h : hits) {
      int r = h[0], c = h[1];
      int removal = 0;
      if (grid[r][c] == 1) {
        grid[r][c] = 0; // mark this grid empty
        for (int d = 0; d < 4; d++) {
          int x = r + dir[d][0], y = c + dir[d][1];
          if (!valid(x, y) || grid[x][y] == 0) {
            continue;
          }
          ++id; // mark each connecting parts with a unique id in this run
          if (falling(grid, x, y)) {
            removal += count(grid, x, y);
          }
        }
      }
      ret.push_back(removal);
    }
    return ret;
  }

private:
  bool falling(vector<vector<int>> &grid, int r, int c) {
    if (!valid(r, c) || grid[r][c] == 0) {
      return true;
    }
    if (visited[r][c] == id) {
      return true; // visited and belongs to the same part this run
    }
    if (r == 0) {
      return false; // connecting 1st row
    }
    visited[r][c] = id;
    for (int d = 0; d < 4; ++d) {
      if (!falling(grid, r + dir[d][0], c + dir[d][1])) {
        return false;
      }
    }
    return true;
  }
  int count(vector<vector<int>> &grid, int r, int c) {
    if (!valid(r, c) || grid[r][c] == 0) {
      return 0;
    }
    int ret = 1;
    grid[r][c] = 0;
    for (int d = 0; d < 4; ++d) {
      ret += count(grid, r + dir[d][0], c + dir[d][1]);
    }
    return ret;
  }
  bool valid(int r, int c) {
    return 0 <= r && r < row_num && 0 <= c && c < col_num;
  }
  vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  int visited[201][201];
  int row_num, col_num, id;
};

int main() {
  Solution so;
  vector<vector<int>> grid{{1, 0, 0, 0}, {1, 1, 1, 0}};
  vector<vector<int>> hits{{1, 0}};

  auto ret = so.hitBricks(grid, hits);
  for (auto i : ret) {
    cout << i << endl;
  }
}
