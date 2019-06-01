// http://leetcode.com/problems/making-a-large-island/description/
#include "xxx.h"

class Solution {
public:
  // n * n grid
  int largestIsland(vector<vector<int>> &grid) {
    n_ = grid[0].size();
    dirs_ = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int ret = 0;
    // 找出所有的岛， 并且给每一坨给个编号
    int index = 2;
    unordered_map<int, int> area;
    for (int i = 0; i < n_; i++) {
      for (int j = 0; j < n_; j++) {
        if (grid[i][j] == 1) {
          int cur_area = dfs(grid, i, j, index);
          ret = max(ret, cur_area);
          // cache
          area[index] = cur_area;
          index++;
        }
      }
    }
    // 遍历所有的0
    for (int i = 0; i < n_; i++) {
      for (int j = 0; j < n_; j++) {
        if (grid[i][j] != 0) {
          continue;
        }
        unordered_set<int> seen = {};
        int cur = 1;
        // 这个0周围有岛吗？有就加起来
        for (auto &dir : dirs_) {
          int nx = i + dir[0];
          int ny = j + dir[1];
          if (nx < 0 || nx >= n_ || ny < 0 || ny >= n_) {
            continue;
          }
          auto cur_index = grid[nx][ny];
          if (cur_index > 1 && seen.count(cur_index) == 0) {
            seen.insert(cur_index);
            cur += area[cur_index];
          }
        }
        ret = max(ret, cur);
      }
    }

    return ret;
  }

private:
  int dfs(vector<vector<int>> &grid, int x, int y, int cur_index) {
    // 至少包含自己嘛
    int area = 1;
    grid[x][y] = cur_index;
    for (auto &dir : dirs_) {
      int nx = x + dir[0];
      int ny = y + dir[1];
      if (nx < 0 || nx >= n_ || ny < 0 || ny >= n_) {
        continue;
      }
      if (grid[nx][ny] == 1) {
        area += dfs(grid, nx, ny, cur_index);
      }
    }

    return area;
  }

private:
  int n_;
  vector<vector<int>> dirs_;
};
int main() {
  Solution so;
  vector<vector<int>> grid{{1, 0}, {0, 1}};

  so.largestIsland(grid);
}
