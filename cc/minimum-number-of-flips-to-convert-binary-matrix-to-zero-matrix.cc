// http://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/description/
#include "xxx.hpp"

class Solution {
public:
  int minFlips(vector<vector<int>> &mat) {
    m_ = mat.size();
    n_ = mat[0].size();

    auto ret = flipOrNotFlip(mat, 0, 0);

    return (ret >= 10000 ? -1 : ret);
  }

private:
  vector<vector<int>> &flip(vector<vector<int>> &mat, int x, int y) {
    mat[x][y] ^= 1;

    if (x - 1 >= 0) {
      mat[x - 1][y] ^= 1;
    }
    if (x + 1 < m_) {
      mat[x + 1][y] ^= 1;
    }
    if (y - 1 >= 0) {
      mat[x][y - 1] ^= 1;
    }
    if (y + 1 < n_) {
      mat[x][y + 1] ^= 1;
    }

    return mat;
  }

  bool isZero(vector<vector<int>> &mat) {
    for (int i = 0; i < m_; i++) {
      for (int j = 0; j < n_; j++) {
        if (mat[i][j]) {
          return false;
        }
      }
    }
    return true;
  }

  // notice the first argument, copy, not reference
  int flipOrNotFlip(vector<vector<int>> mat, int x, int y) {
    if (y == n_) {
      x++;
      y = 0;
    }
    if (x == m_) {
      return isZero(mat) ? 0 : 10000;
    }

    auto ret1 = flipOrNotFlip(mat, x, y + 1);
    auto ret2 = flipOrNotFlip(flip(mat, x, y), x, y + 1) + 1;

    return min(ret1, ret2);
  }

private:
  int m_;
  int n_;
};
