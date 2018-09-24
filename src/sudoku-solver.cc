// http://leetcode.com/problems/sudoku-solver/description/
#include "one.h"
class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) { dfs(board, 0, 0); }

private:
  bool dfs(vector<vector<char>> &board, int curi, int curj) {
    if (curi == 9) {
      return true;
    }
    if (curj == 9) {
      return dfs(board, curi + 1, 0);
    }
    if (board[curi][curj] == '.') {
      for (int k = 1; k <= 9; ++k) {
        board[curi][curj] = (char)('0' + k);
        if (isValidCur(board, curi, curj)) {
          if (dfs(board, curi, curj + 1)) {
            return true;
          }
        }
        // resotre
        board[curi][curj] = '.';
      }
    } else {
      return dfs(board, curi, curj + 1);
    }

    return false;
  }

private:
  // only check current row and colum and the specific small rectangle
  bool isValidCur(vector<vector<char>> &board, int curi, int curj) {
    for (int j = 0; j < 9; j++) {
      if (j != curj && board[curi][j] == board[curi][curj]) {
        return false;
      }
    }
    for (int i = 0; i < 9; i++) {
      if (i != curi && board[i][curj] == board[curi][curj]) {
        return false;
      }
    }
    for (int i = curi / 3 * 3; i < curi / 3 * 3 + 3; ++i) {
      for (int j = curj / 3 * 3; j < curj / 3 * 3 + 3; ++j) {
        if ((i != curi || j != curj) && board[i][j] == board[curi][curj]) {
          return false;
        }
      }
    }

    return true;
  }
};
