// http://leetcode.com/problems/path-with-maximum-gold/description/
#include "xxx.h"

class Solution {
public:
  int getMaximumGold(vector<vector<int>> &grid) {
    m_ = grid.size();
    n_ = grid[0].size();
    dirs_ = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int ret = 0;
    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; ++j) {
        if (grid[i][j] != 0) {
          int cur_gold = 0;
          // dfs
          dfs(grid, i, j, cur_gold);
          ret = max(ret, cur_gold);
        }
      }
    }

    return ret;
  }

private:
  void dfs(vector<vector<int>> &grid, int x, int y, int &gold) {
    int origin = grid[x][y];
    gold += origin;
    grid[x][y] = 0;
    int max_branch{};
    for (int d = 0; d < 4; ++d) {
      int nx = x + dirs_[d][0];
      int ny = y + dirs_[d][1];
      if (nx < 0 || nx >= m_ || ny < 0 || ny >= n_ || grid[nx][ny] == 0) {
        continue;
      }
      // 这里就不能直接递归下去了，选一个最大值
      int cur_branch = 0;
      dfs(grid, nx, ny, cur_branch);
      max_branch = max(max_branch, cur_branch);
    }
    gold += max_branch;

    grid[x][y] = origin;
  }

private:
  int m_;
  int n_;
  vector<vector<int>> dirs_;
};
