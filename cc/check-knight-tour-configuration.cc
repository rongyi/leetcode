// https://leetcode.com/problems/check-knight-tour-configuration/
#include "xxx.hpp"

class Solution {
public:
  bool checkValidGrid(vector<vector<int>> &grid) {
    int n = grid.size();
    int x = 0;
    int y = 0;
    // need to check the initial position
    if (grid[x][y] != 0) {
      return false;
    }
    vector<vector<int>> dirs{{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
                             {1, -2},  {2, -1},  {1, 2},  {2, 1}};
    // for the next value
    int expect_val = 1;
    for (int i = 0; i < n * n - 1; i++) {
      bool jumpok = false;
      for (auto &d : dirs) {
        int nx = x + d[0];
        int ny = y + d[1];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
          continue;
        }
        if (grid[nx][ny] == expect_val) {
          // cout << "jump to pos" << nx << " " << ny << endl;
          jumpok = true;
          x = nx;
          y = ny;
          expect_val++;
          break;
        }
      }
      // can not find valid jump in this round
      if (!jumpok) {
        return false;
      }
    }
    return true;
  }
};
