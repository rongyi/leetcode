// https://leetcode.com/problems/difference-of-number-of-distinct-values-on-diagonals/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> ret(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        set<int> above;
        set<int> below;
        int x = i + 1;
        int y = j + 1;
        while (x < m && y < n) {
          below.insert(grid[x++][y++]);
        }
        x = i - 1;
        y = j - 1;
        while (x >= 0 && y >= 0) {
          above.insert(grid[x--][y--]);
        }
        ret[i][j] = abs((int)below.size() - (int)above.size());
      }
    }

    return ret;
  }
};
