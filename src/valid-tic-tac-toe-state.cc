// https://leetcode.com/problems/valid-tic-tac-toe-state/description/
#include "xxx.h"
class Solution {
public:
  bool validTicTacToe(vector<string> &board) {
    bool xwin = false;
    bool owin = false;
    vector<int> row(3);
    vector<int> col(3);
    int diag = 0;
    int anti_diag = 0;
    // 看落子个数，最终结果只能是X和O相等或者是X比O多一，因为X总是先落子，所以X赢的时候就多一个，输的时候棋子就相等。
    int turn = 0;

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == 'X') {
          if (i == j) {
            ++diag;
          }
          if (i + j == 2) {
            ++anti_diag;
          }
          ++row[i];
          ++col[j];
          ++turn;
        } else if (board[i][j] == 'O') {
          if (i == j) {
            --diag;
          }
          if (i + j == 2) {
            --anti_diag;
          }
          --row[i];
          --col[j];
          --turn;
        }
      }
    }
    auto fn = [](const vector<int> &lst, int value) -> bool {
      for (auto i : lst) {
        if (i == value) {
          return true;
        }
      }
      return false;
    };
    xwin = (diag == 3) || (anti_diag == 3) || fn(col, 3) || fn(row, 3);
    owin = (diag == -3) || (anti_diag == -3) || fn(row, -3) || fn(col, -3);
    if ((xwin && turn == 0) || (owin && turn == 1)) {
      return false;
    }
    //                                  要么只有一个赢的，要么平局，此时等于初始值false
    return (turn == 0 || turn == 1) && (!(xwin && owin));
  }
};
