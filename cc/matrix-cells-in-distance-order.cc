// http://leetcode.com/problems/matrix-cells-in-distance-order/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    const int total = R * C;
    vector<vector<int>> ret(total, vector<int>(2, 0));
    queue<pair<int, int>> q;
    q.push({r0, c0});

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    int i = 0;
    while (!q.empty()) {
      auto cord = q.front();
      q.pop();
      int r = cord.first;
      int c = cord.second;

      if (r < 0 || r >= R || c < 0 || c >= C || visited[r][c]) {
        continue;
      }
      visited[r][c] = true;

      ret[i] = {r, c};
      i++;

      q.push({r, c + 1});
      q.push({r, c - 1});
      q.push({r + 1, c});
      q.push({r - 1, c});
    }

    return ret;
  }
};
