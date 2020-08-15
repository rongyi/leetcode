// http://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/
#include "xxx.h"

class Solution {
public:
  int shortestPath(vector<vector<int>> &grid, int k) {
    m_ = grid.size();
    n_ = grid[0].size();
    dirs_ = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int final_path = numeric_limits<int>::max();

    bfs(0, 0, 0, k, grid, final_path);

    if (final_path == numeric_limits<int>::max()) {
      return -1;
    }

    return final_path;
  }

private:
  void bfs(int cur_path, int x, int y, int k, const vector<vector<int>> &grid,
           int &fpath) {
    // total distance is m_ + n_ - 2
    // still -1 because grid[m_- 1][n_ - 1] always == 0
    // and we can check at each step
    // more verbose description can be found at:
    // https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/discuss/453652/Manhattan-distance-instead-of-normal-goal-check
    if (k >= m_ + n_ - 3 - x - y) {
      fpath = min(fpath, cur_path + m_ + n_ - 2 - x - y);
      return;
    }
    // reach the corner
    if (x == m_ - 1 && y == n_ - 1) {
      fpath = min(fpath, cur_path);
      return;
    }
    if (!cache_.insert(key(x, y, k)).second) {
      return;
    }
    int cur_dist = getDist(x, y);

    for (const auto &d : dirs_) {
      auto nx = x + d[0];
      auto ny = y + d[1];
      if (!valid(nx, ny)) {
        continue;
      }
      int ndist = getDist(nx, ny);
      if (grid[nx][ny] == 0) {
        bfs(cur_path + 1, nx, ny, k, grid, fpath);
      } else if (ndist < cur_dist &&
                 k >= 1) { // more closer and we can eliminate obstacles
        bfs(cur_path + 1, nx, ny, k - 1, grid, fpath);
      }
    }
  }
  bool valid(int x, int y) {
    if (x < 0 || x >= m_ || y < 0 || y >= n_) {
      return false;
    }
    return true;
  }
  string key(int x, int y, int k) {
    return to_string(x) + "#" + to_string(y) + "#" + to_string(k);
  }
  // distance till the end
  int getDist(int x, int y) { return abs(m_ - x - 1) + abs(n_ - y - 1); }

private:
  int m_;
  int n_;
  vector<vector<int>> dirs_;
  unordered_set<string> cache_;
};
