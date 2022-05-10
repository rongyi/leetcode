// https://leetcode.com/problems/count-lattice-points-inside-a-circle/
#include "xxx.hpp"

class Solution {
public:
  int countLatticePoints(vector<vector<int>> &circles) {
    set<pair<int, int>> ins;
    // yes, you can still pass with this naive method
    for (auto &c : circles) {
      int x = c[0];
      int y = c[1];
      int r = c[2];

      int row_left = x - r;
      int row_right = x + r;
      int col_up = y + r;
      int col_down = y - r;
      int r2 = r * r;

      for (int i = row_left; i <= row_right; ++i) {
        for (int j = col_down; j <= col_up; ++j) {
          int dist = (i - x) * (i - x) + (j - y) * (j - y);
          if (dist <= r2) {
            ins.insert({i, j});
          }
        }
      }
    }

    return ins.size();
  }
};
