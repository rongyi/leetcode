// https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/
#include "xxx.hpp"

class Solution {
public:
  int minimumObstacles(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    deque<pair<int, int>> q;
    q.push_back({0, 0});

    vector<vector<int>> dp(m, vector<int>(n, numeric_limits<int>::max()));
    dp[0][0] = 0;

    vector<vector<int>> visited(m, vector<int>(n, 0));
    // mark the visited before enqueue
    visited[0][0] = true;

    while (q.size()) {
      auto cur = q.front();
      q.pop_front();
      int x = cur.first;
      int y = cur.second;
      for (int i = 0; i < 4; ++i) {
        int nx = x + dirs_[i][0];
        int ny = y + dirs_[i][1];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
          continue;
        }
        if (visited[nx][ny]) {
          continue;
        }
        // and obstacle? then add one removal action
        dp[nx][ny] = dp[x][y] + (grid[nx][ny] == 1);
        // in a sorted way
        if (grid[nx][ny] == 1) {
          q.push_back({nx, ny});
        } else {
          q.push_front({nx, ny});
        }
        // how about we delay this before this for loop?
        // no, we can do this, we mark all neighbor visited
        // if we delay this above for, we will meet some
        // unvisited node
        // mark all this layer visited, we will never waste
        // some step
        visited[nx][ny] = true;
      }
    }

    return dp[m - 1][n - 1];
  }

private:
  vector<vector<int>> dirs_{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};
