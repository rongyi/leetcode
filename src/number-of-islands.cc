// https://www.lintcode.com/problem/number-of-distinct-islands/
#include "one.h"

class Solution {
public:
  /**
   * @param grid: a list of lists of integers
   * @return: return an integer, denote the number of distinct islands
   */
  int numIslands(vector<vector<char>> &grid) {
    if (grid.empty()) {
      return 0;
    }
    int ret = 0;
    m_ = grid.size();
    n_ = grid[0].size();

    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; ++j) {
        if (grid[i][j] == '1') {
          ++ret;
          dfs(grid, i, j);
        }
      }
    }
    return ret;
  }

private:
  void dfs(vector<vector<char>> &grid, int i, int j) {
    if (i < 0 || i >= m_ || j < 0 || j >= n_) {
      return;
    }
    if (grid[i][j] == '1') {
      grid[i][j] = '0';
      dfs(grid, i + 1, j);
      dfs(grid, i - 1, j);
      dfs(grid, i, j + 1);
      dfs(grid, i, j - 1);
    }
  }

private:
  int m_;
  int n_;
};

int main() {
  vector<vector<bool>> input = {{1, 1, 0, 0, 0},
                               {0, 1, 0, 0, 1},
                               {0, 0, 0, 1, 1},
                               {0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 1}};
  Solution so;
  auto ret = so.numIslands(input);
  cout << ret << endl;
}
