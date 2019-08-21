// http://leetcode.com/problems/shortest-path-in-binary-matrix/description/
#include "xxx.h"
#include <utility>

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int ret = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
      ++ret;
      queue<pair<int, int>> q1;
      while (!q.empty()) {
        auto c = q.front();
        q.pop();
        // c++14
        // if (exchange(grid[c.first][c.second], 1) == 1) {
        //   continue;
        // }
        if (grid[c.first][c.second] == 1) {
          continue;
        }
        // set to visited
        grid[c.first][c.second] = 1;
        // nxn matrix
        if (c.first == grid.size() - 1 && c.second == grid.size() - 1) {
          return ret;
        }
        // 八个方向
        // .  .  .
        //    |
        // .__|__.
        //    |
        // .  .  .
        for (auto i = c.first - 1; i <= c.first + 1; ++i) {
          for (auto j = c.second - 1; j <= c.second + 1; ++j) {
            // 八个方向不能包括中间那个原点
            if (i != c.first || j != c.second) {
              if (i >= 0 && i < grid.size() && j >= 0 && j < grid.size() &&
                  !grid[i][j]) {
                q1.push({i, j});
              }
            }
          }
        }
      }

      swap(q, q1);
    }

    return -1;
  }
};
