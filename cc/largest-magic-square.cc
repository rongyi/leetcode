#include "xxx.h"

class Solution {
public:
  int largestMagicSquare(vector<vector<int>> &grid) {
    m_ = grid.size();
    n_ = grid[0].size();
    row_prefix_ = vector<vector<int>>(m_, vector<int>(n_ + 1, 0));
    col_prefix_ = vector<vector<int>>(n_, vector<int>(m_ + 1, 0));
    // calculate prefix sum
    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; ++j) {
        row_prefix_[i][j + 1] = row_prefix_[i][j] + grid[i][j];
        // NOTE: col prefix has j row, think as col prefix
        // is rotated 90 degree anti colck wise
        col_prefix_[j][i + 1] = col_prefix_[j][i] + grid[i][j];
      }
    }

    for (int k = min(m_, n_); k >= 2; k--) {
      if (valid(grid, k)) {
        return k;
      }
    }

    return 1;
  }

private:
  bool valid(vector<vector<int>> &grid, int k) {
    for (int r = 0; r + k - 1 < m_; ++r) {
      for (int c = 0; c + k - 1 < n_; ++c) {
        int diag = 0;
        int anti_diag = 0;
        for (int d = 0; d < k; ++d) {
          diag += grid[r + d][c + d];
          anti_diag += grid[r + d][c + k - 1 - d];
        }
        bool match = (diag == anti_diag);
        // check every row
        for (int i = r; i < r + k && match; ++i) {
          match = (diag == (row_prefix_[i][c + k - 1 + 1] - row_prefix_[i][c]));
        }
        // check every col
        for (int j = c; j < c + k && match; ++j) {
          match = (diag == (col_prefix_[j][r + k - 1 + 1] - col_prefix_[j][r]));
        }
        if (match) {
          return true;
        }
      }
    }
    return false;
  }

private:
  vector<vector<int>> row_prefix_;
  vector<vector<int>> col_prefix_;
  int m_;
  int n_;
};
