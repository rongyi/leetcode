// http://leetcode.com/problems/valid-sudoku/description/
#include "xxx.hpp"
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++) {
      set<char> row_cnt;
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == '.') {
          continue;
        }
        if (row_cnt.count(board[i][j])) {
          return false;
        }
        row_cnt.insert(board[i][j]);
      }
    }

    for (int j = 0; j < n; ++j) {
      set<char> col_cnt;
      for (int i = 0; i < m; i++) {
        if (board[i][j] == '.') {
          continue;
        }
        if (col_cnt.count(board[i][j])) {
          return false;
        }
        col_cnt.insert(board[i][j]);
      }
    }

    for (int r = 0; r < 3; ++r) {
      for (int c = 0; c < 3; ++c) {
        set<char> cnt;
        for (int i = r * 3; i < r * 3 + 3; ++i) {
          for (int j = c * 3; j < c * 3 + 3; ++j) {
            if (board[i][j] == '.') {
              continue;
            }
            if (cnt.count(board[i][j])) {
              return false;
            }
            cnt.insert(board[i][j]);
          }
        }
      }
    }

    return true;
  }
};
