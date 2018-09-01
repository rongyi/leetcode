// https://leetcode.com/problems/transform-to-chessboard/description/
#include "one.h"

class Solution {
public:
  int movesToChessboard(vector<vector<int>> &board) {
    const int n = board.size();
    // 任何四角都只能是四个1，四个0， 或者各一半
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[0][0] ^ board[0][j] ^ board[i][j] ^ board[i][0]) {
          return -1;
        }
      }
    }
    int row_sum = 0;
    int col_sum = 0;
    for (int i = 0; i < n; ++i) {
      row_sum += board[0][i];
      col_sum += board[i][0];
    }

    if ((n >> 1) > row_sum || row_sum > ((n + 1) >> 1) || (n >> 1) > col_sum ||
        col_sum > ((n + 1) >> 1)) {
      return -1;
    }

    // now count
    int row_swap = 0;
    int col_swap = 0;

    // 默认按照010101这样为合法
    for (int i = 0; i < n; ++i) {
      if ((i & 1) != board[i][0]) {
        row_swap += 1;
      }
      if ((i & 1) != board[0][i]) {
        col_swap += 1;
      }
    }

    if ((n & 1)) {
      if (row_swap & 1) {
        row_swap = n - row_swap;
      }
      if (col_swap & 1) {
        col_swap = n - col_swap;
      }
    } else {
      row_swap = min(row_swap, n - row_swap);
      col_swap = min(col_swap, n - col_swap);
    }
    return (row_swap + col_swap) >> 1;
  }
};
