// https://leetcode.com/problems/escape-the-spreading-fire/
#include "xxx.hpp"

class Solution {
public:
  int maximumMinutes(vector<vector<int>> &grid) {
    int fire_noway = 1e9;
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> fires;
    queue<pair<int, int>> person;
    person.push({0, 0});

    // fill fires
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          fires.push({i, j});
        }
      }
    }
    auto bfs = [&](queue<pair<int, int>> &q) {
      vector<vector<int>> walk_grid(m, vector<int>(n, 0));
      while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int curx = cur.first;
        int cury = cur.second;
        for (auto d : dirs_) {
          int nx = curx + d[0];
          int ny = cury + d[1];
          // invalid node
          if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
            continue;
          }
          // whichever one goes to a node ,this is
          // the shorted path, so we won't touch node which value
          // is not 0!
          if (grid[nx][ny] == 0 && walk_grid[nx][ny] == 0) {
            walk_grid[nx][ny] = walk_grid[curx][cury] + 1;
            q.push({nx, ny});
          }
        }
      }
      return array<int, 3>{walk_grid[m - 1][n - 1], walk_grid[m - 2][n - 1],
                           walk_grid[m - 1][n - 2]};
    };
    auto fire_steps = bfs(fires);
    auto person_stpes = bfs(person);
    if (fire_steps[0] == 0 && person_stpes[0] != 0) {
      return fire_noway;
    }
    int diff = fire_steps[0] - person_stpes[0];
    if (person_stpes[0] != 0 && diff >= 0) {
      if (fire_steps[1] - person_stpes[1] <= diff &&
          fire_steps[2] - person_stpes[2] <= diff) {
        diff -= 1;
      }
      return diff;
    }

    return -1;
  }

private:
  vector<vector<int>> dirs_{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};
