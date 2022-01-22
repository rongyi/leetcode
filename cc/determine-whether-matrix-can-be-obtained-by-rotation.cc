// http://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/
#include "xxx.hpp"

class Solution {
public:
  bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target) {
    if (equalMatrix(mat, target)) {
      return true;
    }

    // not the transform position
    // clock wise 90
    int n = mat.size();
    vector<vector<int>> tmp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        tmp[j][n - i - 1] = mat[i][j];
      }
    }

    if (equalMatrix(tmp, target)) {
      return true;
    }

    // clock wise 180
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; ++j) {
        tmp[n - i - 1][n - j - 1] = mat[i][j];
      }
    }
    if (equalMatrix(tmp, target)) {
      return true;
    }
    // clock wise 270
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        tmp[n - j - 1][i] = mat[i][j];
      }
    }
    if (equalMatrix(tmp, target)) {
      return true;
    }

    return false;
  }

private:
  bool equalMatrix(vector<vector<int>> &l, vector<vector<int>> &r) {
    int n = l.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (l[i][j] != r[i][j]) {
          return false;
        }
      }
    }
    return true;
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{0, 1}, {1, 1}};
  vector<vector<int>> target{{1, 0}, {0, 1}};
  so.findRotation(input, target);
}
