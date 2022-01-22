// http://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/description/
#include "xxx.hpp"
class Solution {
public:
  // https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/discuss/434574/BFS-%2B-DFS-Simple-C%2B%2B-solution-or-Easy-to-understand-with-Explanation
  int minPushBox(vector<vector<char>> &grid) {
    dirs_ = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    const int m = grid.size();
    const int n = grid[0].size();

    // find each position
    int target{};
    int box{};
    int player{};
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        // Player
        if (grid[i][j] == 'S') {
          player = i * n + j;
        }
        if (grid[i][j] == 'B') {
          box = i * n + j;
        }
        if (grid[i][j] == 'T') {
          target = i * n + j;
        }
      }
    }

    // player box pair position cache
    set<pair<int, int>> visited;
    visited.insert({player, box});

    // move box to all it's eligible neighbor
    queue<pair<int, int>> q;
    q.push({player, box});

    int ret = 0;
    while (!q.empty()) {
      ++ret;

      const int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        auto cur_pair = q.front();
        q.pop();

        int box_x = cur_pair.second / n;
        int box_y = cur_pair.second % n;

        auto cur_player = cur_pair.first;

        grid[box_x][box_y] = '#';
        for (int d = 0; d < 4; ++d) {
          int nex_box_x = box_x + dirs_[d][0];
          int nex_box_y = box_y + dirs_[d][1];

          int px = box_x - dirs_[d][0];
          int py = box_y - dirs_[d][1];

          vector<vector<int>> walk(m, vector<int>(n, 0));
          if (isValid(grid, nex_box_x, nex_box_y) &&
              canWalk(grid, cur_player / n, cur_player % n, px, py, walk) &&
              visited.count({px * n + py, nex_box_x * n + nex_box_y}) == 0) {
            if (nex_box_x == target / n && nex_box_y == target % n) {
              return ret;
            }

            visited.insert({px * n + py, nex_box_x * n + nex_box_y});
            q.push({px * n + py, nex_box_x * n + nex_box_y});
          }
        }

        grid[box_x][box_y] = '.';
      }
    }

    return -1;
  }

private:
  bool isValid(vector<vector<char>> &grid, int x, int y) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() ||
        grid[x][y] == '#') {
      return false;
    }
    return true;
  }
  // from (x, y) ==> (tx, ty) ?
  bool canWalk(vector<vector<char>> &grid, int x, int y, int tx, int ty,
               vector<vector<int>> &walk) {
    if (x == tx && y == ty) {
      return true;
    }
    for (int i = 0; i < 4; ++i) {
      int nx = x + dirs_[i][0];
      int ny = y + dirs_[i][1];
      if (isValid(grid, nx, ny) && walk[nx][ny] == 0) {
        walk[nx][ny] = 1;
        if (canWalk(grid, nx, ny, tx, ty, walk)) {
          return true;
        }
      }
    }
    return false;
  }

private:
  vector<vector<int>> dirs_;
};
