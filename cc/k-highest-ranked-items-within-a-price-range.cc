// https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid,
                                          vector<int> &pricing,
                                          vector<int> &start, int k) {
    // Distance, defined as the length of the shortest path from the start
    // (shorter distance has a higher rank).

    // Price (lower price has a higher rank, but it must be in the price range).

    // The row number (smaller row number has a higher rank).

    // The column number (smaller column number has a higher rank).
    // do as they say, 4 priority order
    // {layer, price, x, y}
    vector<array<int, 4>> valid_candidates;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    // init quueue
    queue<pair<int, int>> q;
    q.push({start[0], start[1]});
    visited[start[0]][start[1]] = true;

    int layer = -1;
    int price_low = pricing[0];
    int price_high = pricing[1];
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!q.empty()) {
      layer += 1;
      int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        auto [x, y] = q.front();
        q.pop();

        // a wall we can not pass
        // they don't make sure the start pos is valid
        // drop this check make this ac much slower!
        if (grid[x][y] == 0) {
          continue;
        }
        // a valid candidate?
        if (grid[x][y] <= price_high && grid[x][y] >= price_low) {
          valid_candidates.push_back({layer, grid[x][y], x, y});
        }
        for (int d = 0; d < 4; ++d) {
          int nx = x + dirs[d][0];
          int ny = y + dirs[d][1];
          // not in range
          if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
            continue;
          }
          // visited or a zero grid which means wall we can not pass
          if (grid[nx][ny] == 0 || visited[nx][ny]) {
            continue;
          }
          visited[nx][ny] = true;
          q.push({nx, ny});
        }
      }
    }
    vector<vector<int>> ret;
    sort(begin(valid_candidates), end(valid_candidates));
    for (int i = 0; i < min(k, (int)valid_candidates.size()); ++i) {
      ret.push_back({valid_candidates[i][2], valid_candidates[i][3]});
    }

    return ret;
  }
};
