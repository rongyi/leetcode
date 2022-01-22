// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
#include "xxx.hpp"

using pii = pair<int, int>;
class Solution {
public:
  int nearestExit(vector<vector<char>> &maze, vector<int> &origin) {
    int m = maze.size();
    int n = maze[0].size();
    dirs_ = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    queue<pii> q;
    // queue<pii> q2;
    q.push({origin[0], origin[1]});

    // mark origin as wall, so even origin is at border
    // we still can not get out
    maze[origin[0]][origin[1]] = '+';
    int layer = 0;

    while (!q.empty()) {
      auto sz = q.size();
      layer++;
      for (int i = 0; i < sz; ++i) {
        auto cur = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
          int nx = cur.first + dirs_[d][0];
          int ny = cur.second + dirs_[d][1];
          // not valid
          if (nx < 0 || nx >= m || ny < 0 || ny >= n || maze[nx][ny] == '+') {
            continue;
          }
          // at border?
          // yes! go out
          if (nx == 0 || nx == m - 1 || ny == 0 || ny == n - 1) {
            return layer;
          }
          q.push({nx, ny});
          // mark as visited, so we won't go to here again
          maze[nx][ny] = '+';
        }
      }
    }

    return -1;
  }

private:
  vector<vector<int>> dirs_;
};
