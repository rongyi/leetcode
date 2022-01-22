// http://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/
#include "xxx.hpp"

class Solution {
public:
  int minCost(vector<vector<int>> &grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    // pos, path cost
    deque<pair<int, int>> dq;
    dq.push_back({0, 0});

    vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    unordered_set<int> visited;

    int ret = 0;
    while (!dq.empty()) {
      auto cur = dq.front();
      auto curi = cur.first / n;
      auto curj = cur.first % n;
      dq.pop_front();
      if (visited.insert(cur.first).second) {
        ret = cur.second;
      }
      if (curi == m - 1 && curj == n - 1) {
        return ret;
      }
      for (auto &dir : dirs) {
        int x = curi + dir[0];
        int y = curj + dir[1];
        int pos = x * n + y;
        if (x < 0 || x >= m || y < 0 || y >= n || visited.count(pos)) {
          continue;
        }

        int cost;
        // desire direction
        if (grid[curi][curj] == 1 && dir[0] == 0 && dir[1] == 1) {
          cost = 0;
        } else if (grid[curi][curj] == 2 && dir[0] == 0 && dir[1] == -1) {
          cost = 0;
        } else if (grid[curi][curj] == 3 && dir[0] == 1 && dir[1] == 0) {
          cost = 0;
        } else if (grid[curi][curj] == 4 && dir[0] == -1 && dir[1] == 0) {
          cost = 0;
        } else {
          cost = 1;
        }

        if (cost == 1) {
          dq.push_back({pos, cur.second + cost});
        } else {
          dq.push_front({pos, cur.second + cost});
        }
      }
    }
    return ret;
  }
};
