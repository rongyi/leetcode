// http://leetcode.com/problems/valid-sudoku/description/
#include "one.h"
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    const int m = 9;
    const int n = 9;
    // check 9 long row
    for (int i = 0; i < m; ++i) {
      unordered_set<char> cur;
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == '.') {
          continue;
        }
        // find repeated element
        if (cur.find(board[i][j]) != cur.end()) {
          return false;
        }
        cur.insert(board[i][j]);
      }
    }

    // check 9 long col
    for (int j = 0; j < n; ++j) {
      unordered_set<char> cur;
      for (int i = 0; i < m; ++i) {
        if (board[i][j] == '.') {
          continue;
        }
        if (cur.find(board[i][j]) != cur.end()) {
          return false;
        }
        cur.insert(board[i][j]);
      }
    }

    // check 3 * 3 small row * col
    for (int r = 0; r < 3; ++r) {
      for (int c = 0; c < 3; ++c) {
        unordered_set<char> cur;
        for (int i = r * 3; i < r * 3 + 3; ++i) {
          for (int j = c * 3; j < c * 3 + 3; ++j) {
            if (board[i][j] == '.') {
              continue;
            }
            if (cur.find(board[i][j]) != cur.end()) {
              return false;
            }
            cur.insert(board[i][j]);
          }
        }
      }
    }

    return true;
  }
};
