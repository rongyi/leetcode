// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/
#include "xxx.hpp"

class Solution {
public:
  int maxMoves(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    dirs_ = {{-1, 1}, {0, 1}, {1, 1}};
    int ret = 0;
    vector<vector<int>> cp = grid;
    for (int i = 0; i < m; i++) {
      grid = cp;
      int layers = 0;
      queue<pair<int, int>> q;
      q.push({i, 0});
      while (!q.empty()) {
        layers++;
        int sz = q.size();
        for (int j = 0; j < sz; j++) {
          auto cur = q.front();
          q.pop();
          for (int d = 0; d < dirs_.size(); d++) {
            auto nx = cur.first + dirs_[d][0];
            auto ny = cur.second + dirs_[d][1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n ||
                grid[nx][ny] <= grid[cur.first][cur.second]) {
              continue;
            }
            // a valid path
            q.push({nx, ny});
          }

          // mark as visited
          grid[cur.first][cur.second] = 1e6 + 1;
        }
      }

      ret = max(ret, layers - 1);
    }

    return ret;
  }

private:
  vector<vector<int>> dirs_;
};
