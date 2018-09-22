#include "one.h"

int main() {
  int i = 1e6;
  cout << i << endl;
  for (int j = 1; j < 31; ++j) {
    if ((1 << j) > i) {
      cout << "here" << j << endl;
      break;
    }
  }
}
struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
  vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
  int numberofDistinctIslands(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    set<vector<pair<int, int>>> res;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] != 1)
          continue;
        vector<pair<int, int>> v;
        helper(grid, i, j, i, j, v);
        res.insert(v);
      }
    }
    return res.size();
  }
  void helper(vector<vector<int>> &grid, int x0, int y0, int i, int j,
              vector<pair<int, int>> &v) {
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= 0)
      return;
    grid[i][j] *= -1;
    v.push_back({i - x0, j - y0});
    for (auto dir : dirs) {
      helper(grid, x0, y0, i + dir[0], j + dir[1], v);
    }
  }
};
