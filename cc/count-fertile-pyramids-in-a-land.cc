// https://leetcode.com/problems/count-fertile-pyramids-in-a-land/
#include "xxx.hpp"

class Solution {
public:
  int countPyramids(vector<vector<int>> &grid) {
    int ret = 0;

    ret += countInverse(grid);
    reverse(grid.begin(), grid.end());
    ret += countInverse(grid);

    return ret;
  }

private:
  int countInverse(vector<vector<int>> grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ret = 0;

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        if (grid[i][j] && grid[i - 1][j]) {
          grid[i][j] = min(grid[i - 1][j - 1], grid[i - 1][j + 1]) + 1;
          ret += grid[i][j] -
                 1; // pyramid of size n contributes n - 1 times to the answer.
        }
      }
    }

    return ret;
  }
};
