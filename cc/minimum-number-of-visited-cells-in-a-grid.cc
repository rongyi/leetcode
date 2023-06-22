// https://leetcode.com/problems/minimum-number-of-visited-cells-in-a-grid/
#include "xxx.hpp"

class Solution {
public:
  int minimumVisitedCells(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    // bfs with prune, but visited cache need to pay attention
    // each row can reach the range, like the visited cache
    vector<set<int>> col_can_reach_for_row_of(m);
    vector<set<int>> row_can_reach_for_col_of(n);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        col_can_reach_for_row_of[i].insert(j);
        row_can_reach_for_col_of[j].insert(i);
      }
    }


    queue<vector<int>> q;
    // initial step = 0;
    q.push({0, 0, 1});

    while (!q.empty()) {
      // layer by layer
      auto cur = q.front();
      q.pop();

      int x = cur[0];
      int y = cur[1];
      int step = cur[2];
      if (x == m - 1 && y == n - 1) {
        return step;
      }
      // the next range can reach
      auto it = col_can_reach_for_row_of[x].lower_bound(y + 1);
      while (it != col_can_reach_for_row_of[x].end() && *it <= y + grid[x][y]) {
        q.push({x, *it, step + 1});
        row_can_reach_for_col_of[*it].erase(x);
        col_can_reach_for_row_of[x].erase(it++);
      }

      it = row_can_reach_for_col_of[y].lower_bound(x + 1);
      while (it != row_can_reach_for_col_of[y].end() && *it <= x + grid[x][y]) {
        q.push({*it, y, step + 1});
        col_can_reach_for_row_of[*it].erase(y);
        row_can_reach_for_col_of[y].erase(it++);
      }
    }

    return -1;
  }
};
