// http://leetcode.com/problems/number-of-distinct-islands/description/
#include "one.h"

class Solution {
public:
  /**
   * @param grid: a list of lists of integers
   * @return: return an integer, denote the number of distinct islands
   */
  int numberofDistinctIslands(vector<vector<int>> &grid) {
    m_ = grid.size();
    n_ = grid[0].size();
    set<vector<pair<int, int>>> ret;

    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; j++) {
        if (grid[i][j] == 1) {
          vector<pair<int, int>> v;
          dfs(grid, i, j, i, j, v);
          ret.insert(v);
        }
      }
    }

    return ret.size();
  }

private:
  void dfs(vector<vector<int>> &grid, int ox, int oy, int x, int y,
           vector<pair<int, int>> &v) {
    if (x < 0 || x >= m_ || y < 0 || y >= n_) {
      return;
    }
    if (grid[x][y] == 1) {
      grid[x][y] = 0;
      v.push_back({x - ox, y - oy});

      // whatever the corner oder, every one just obey it
      dfs(grid, ox, oy, x + 1, y, v);
      dfs(grid, ox, oy, x - 1, y, v);
      dfs(grid, ox, oy, x, y + 1, v);
      dfs(grid, ox, oy, x, y - 1, v);
    }
  }

private:
  int m_;
  int n_;
};

int main() {
  Solution so;
  vector<vector<int>> input{{1, 1, 0, 1, 1}, {1, 0, 0, 0, 0}, {0, 0, 0, 0, 1}, { 1, 1, 0, 1, 1 }};
  auto ret = so.numberofDistinctIslands(input);
  cout << ret << endl;
}
