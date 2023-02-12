// http://leetcode.com/problems/sudoku-solver/description/
#include "xxx.hpp"
class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) { dfs(board, 0, 0); }

private:
  bool dfs(vector<vector<char>> &b, int x, int y) {
    if (x == 9) {
      return true;
    }
    if (y == 9) {
      return dfs(b, x + 1, 0);
    }
    if (b[x][y] != '.') {
      return dfs(b, x, y + 1);
    }
    for (int k = 1; k <= 9; k++) {
      b[x][y] = k + '0';
      if (isValidCur(b, x, y)) {
        if (dfs(b, x, y + 1)) {
          return true;
        }
      }
      b[x][y] = '.';
    }

    return false;
  }

private:
  // only check current row and colum and the specific small rectangle
  bool isValidCur(vector<vector<char>> &b, int x, int y) {
    for (int i = 0; i < 9; i++) {
      if (i != x && b[i][y] == b[x][y]) {
        return false;
      }
    }
    for (int j = 0; j < 9; j++) {
      if (j != y && b[x][j] == b[x][y]) {
        return false;
      }
    }
    int r = x / 3;
    int c = y / 3;
    for (int i = r * 3; i < r * 3 + 3; i++) {
      for (int j = c * 3; j < c * 3 + 3; j++) {
        if ((i != x || j != y) && b[i][j] == b[x][y]) {
          return false;
        }
      }
    }
    return true;
  }
};
