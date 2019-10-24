// http://leetcode.com/problems/as-far-from-land-as-possible/description/
#include "xxx.h"

class Solution {
public:
  int maxDistance(vector<vector<int>> &grid) {
    const int n = grid.size();
    queue<pair<int, int>> q;
    queue<pair<int, int>> q2;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          // visit neighbors
          q.push({i + 1, j});
          q.push({i - 1, j});
          q.push({i, j + 1});
          q.push({i, j - 1});
        }
      }
    }

    int steps = 0;

    while (!q.empty()) {
      ++steps;
      while (!q.empty()) {
        auto i = q.front().first;
        auto j = q.front().second;
        q.pop();
        if (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 0) {
          grid[i][j] = steps;
          q2.push({i + 1, j});
          q2.push({i - 1, j});
          q2.push({i, j + 1});
          q2.push({i, j - 1});
        }
      }
      swap(q, q2);
    }

    return steps == 1 ? -1 : steps - 1;
  }
};
