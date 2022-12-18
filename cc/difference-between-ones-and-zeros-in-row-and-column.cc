// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> rows(m, 0);
    vector<int> cols(n, 0);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          rows[i]++;
          cols[j]++;
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        // grid[i][j] = rows[i] + cols[j] - (m - rows[i]) - (n - cols[j]);
        grid[i][j] = rows[i] * 2 + cols[j] * 2 - m - n;
      }
    }

    return grid;
  }
};
