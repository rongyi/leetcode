// https://leetcode.com/problems/last-day-where-you-can-still-cross/
#include "xxx.hpp"

class Solution {
public:
  int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
    dirs_ = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int left = 1;
    int right = cells.size();
    int ret = 0;
    while (left <= right) {
      auto mid = left + (right - left) / 2;
      if (canWalk(cells, row, col, mid)) {
        ret = mid;
        left = mid + 1; // see if we can visit the bottom after this line
      } else {
        right = mid - 1;
      }
    }

    return ret;
  }

private:
  bool canWalk(vector<vector<int>> &cells, int row, int col, int curDay) {
    // create grid and flood with it
    // 0 land
    // 1 water
    vector<vector<int>> grid(row, vector<int>(col, 0));
    for (int i = 0; i < curDay; ++i) {
      // flood with walter
      grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
    }
    // bfs
    queue<pair<int, int>> q;
    // find valid starting point in first row
    for (int j = 0; j < col; ++j) {
      if (grid[0][j] == 0) {
        q.push({0, j});
        grid[0][j] = 1; // 1 as visited
      }
    }
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      if (x == row - 1) {
        return true;
      }
      for (int d = 0; d < 4; ++d) {
        auto nx = x + dirs_[d][0];
        auto ny = y + dirs_[d][1];
        if (nx < 0 || nx >= row || ny < 0 || ny >= col || grid[nx][ny] == 1) {
          continue;
        }
        q.push({nx, ny});
        grid[nx][ny] = 1;
      }
    }

    return false;
  }

private:
  vector<vector<int>> dirs_;
};
