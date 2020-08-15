// http://leetcode.com/problems/contain-virus/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/contain-virus/discuss/110186/C%2B%2B-DFS-12ms
  int containVirus(vector<vector<int>> &grid) {
    m_ = grid.size();
    n_ = grid[0].size();
    int ret = 0;
    while (true) {
      int walls = process(grid);
      if (walls == 0) {
        break;
      }
      ret += walls;
    }
    return ret;
  }

private:
  int process(vector<vector<int>> &grid) {
    // max area to be affected by a single virus region
    int cnt = 0;
    // corresponding walls
    int ret = 0;

    vector<vector<int>> visited(m_, vector<int>(n_, 0));
    int color = -1;
    int row = -1;
    int col = -1;
    for (int i = 0; i < m_; i++) {
      for (int j = 0; j < n_; j++) {
        if (grid[i][j] == 1 && visited[i][j] == 0) {
          int walls = 0;
          int area = dfs(grid, visited, i, j, color, walls);
          if (area > cnt) {
            ret = walls;
            cnt = area;
            row = i;
            col = j;
          }
          color--;
        }
      }
    }
    buildWall(grid, row, col);
    // propagate other virus by 1 step
    visited = vector<vector<int>>(m_, vector<int>(n_, 0));
    for (int i = 0; i < m_; i++) {
      for (int j = 0; j < n_; j++) {
        if (grid[i][j] == 1 && visited[i][j] == 0)
          spread(grid, visited, i, j);
      }
    }
    return ret;
  }
  int dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int row,
          int col, int color, int &walls) {
    int ans = 0;
    if (row < 0 || row >= m_ || col < 0 || col >= n_)
      return 0;
    if (grid[row][col] == 0) {
      walls++;
      if (visited[row][col] == color)
        return 0;
      visited[row][col] = color;
      return 1;
    }
    // grid[row][col] could be -1, inactive virus
    if (visited[row][col] == 1 || grid[row][col] != 1) {
      return 0;
    }
    visited[row][col] = 1;
    vector<int> dir = {-1, 0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
      ans += dfs(grid, visited, row + dir[i], col + dir[i + 1], color, walls);
    }
    return ans;
  }
  void buildWall(vector<vector<int>> &grid, int row, int col) {
    if (row < 0 || row >= m_ || col < 0 || col >= n_ || grid[row][col] != 1) {
      return;
    }
    grid[row][col] = -1; // set inactive
    vector<int> dir = {-1, 0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
      buildWall(grid, row + dir[i], col + dir[i + 1]);
    }
  }
  void spread(vector<vector<int>> &grid, vector<vector<int>> &visited, int row,
              int col) {
    if (row < 0 || row >= m_ || col < 0 || col >= n_ ||
        visited[row][col] == 1) {
      return;
    }
    if (grid[row][col] == 0) {
      grid[row][col] = 1;
      visited[row][col] = 1;
    } else if (grid[row][col] == 1) {
      visited[row][col] = 1;
      vector<int> dir = {-1, 0, 1, 0, -1};
      for (int i = 0; i < 4; i++) {
        spread(grid, visited, row + dir[i], col + dir[i + 1]);
      }
    }
  }

private:
  int m_;
  int n_;
};
