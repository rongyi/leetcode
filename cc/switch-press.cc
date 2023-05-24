#include "xxx.hpp"

class Solution {
public:
  bool check(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    directions_ = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<vector<int>> cp = matrix;

    // all permutation for first, means we need to press the button of index i
    for (int p = 0; p < (1 << m); p++) {
      for (int j = 0; j < n; j++) {
        // we need press this button
        if ((p >> j) & 1) {
          toggle(matrix, 0, j, m, n);
        }
      }

      for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n; j++) {
          if (matrix[i][j] == 0) {
            // we must press the buttom under current one
            toggle(matrix, i + 1, j, m, n);
          }
        }
      }
      // check the final status
      bool has_off = false;
      for (int j = 0; j < n; j++) {
        // shit
        if (matrix[m - 1][j] == 0) {
          has_off = true;
          break;
        }
      }
      if (!has_off) {
        return true;
      }

      // try again
      matrix = cp;
    }

    return false;
  }
  void toggle(vector<vector<int>> &matrix, int x, int y, int m, int n) {
    for (int d = 0; d < 4; d++) {
      int nx = x + directions_[d][0];
      int ny = y + directions_[d][1];
      if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
        continue;
      }
      matrix[nx][ny] ^= 1;
    }
    // and itself
    matrix[x][y] ^= 1;
  }

private:
  vector<vector<int>> directions_;
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<vector<int>> input{{0, 1, 0, 1, 1},
                            {1, 0, 1, 1, 0},
                            {1, 0, 1, 0, 0},
                            {0, 0, 0, 1, 1},
                            {1, 1, 0, 1, 1}};
  cout << so.check(input) << endl;

  return 0;
}
