// https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/
#include "xxx.hpp"

class Solution {
public:
  int minimumTime(vector<vector<int>> &grid) {
    // if we can walk one step we can walk back and forth(ping pong)
    // to wait the time to reach the target
    // else we can do nothing
    if (grid[0][1] > 1 && grid[1][0] > 1) {
      return -1;
    }
    // else we can pingpong to reach bottom right
    // {path time consumption, x, y}
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, false));
    vector<vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    pq.push({grid[0][0], 0, 0});
    while (!pq.empty()) {
      int cur_time = pq.top()[0];
      int x = pq.top()[1];
      int y = pq.top()[2];
      pq.pop();

      if (x == m - 1 && y == n - 1) {
        return cur_time;
      }
      if (visited[x][y]) {
        continue;
      }
      visited[x][y] = true;

      for (auto &d : dirs) {
        auto nx = x + d[0];
        auto ny = y + d[1];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) {
          continue;
        }
        // et's say time for target cell is 4 and current time is 2, difference
        // = 2 (even).
        // Move to prev cell, time = 3
        // Move to curr cell, time = 4
        // Move to target cell, time = 5.
        // Hence we reach target cell with time: target cell time + 1 when
        // difference between target cell time and curr cell time is even.
        //
        // Let's say time for target cell is 5 and current time is 2, difference
        // = 3 (odd). Move to prev cell, time = 3 Move to curr cell, time = 4
        // Move to target cell, time = 5. Hence we reach target cell with time:
        // target cell time when difference between target cell time and curr
        // cell time is odd.
        int wait = (grid[nx][ny] - cur_time) % 2 == 0;
        pq.push({max(grid[nx][ny] + wait, cur_time + 1), nx, ny});
      }
    }

    return -1;
  }
};
