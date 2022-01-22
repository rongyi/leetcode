// http://leetcode.com/problems/where-will-the-ball-fall/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> findBall(vector<vector<int>> &grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<int> ret;
    for (int b = 0; b < n; ++b) {
      int i = 0;
      int j = b;
      for (; i < m; ++i) {
        // right direction
        if (grid[i][j] == 1) {
          if (j == n - 1 || grid[i][j + 1] != grid[i][j]) {
            break;
          }
          j++;
        } else {
          // left direction case
          if (j == 0 || grid[i][j - 1] != grid[i][j]) {
            break;
          }
          j--;
        }
      }
      if (i == m) {
        ret.push_back(j);
      } else {
        ret.push_back(-1);
      }
    }

    return ret;
  }
};
