// https://leetcode.com/problems/check-if-move-is-legal/
#include "xxx.h"

class Solution {
public:
  bool checkMove(vector<vector<char>> &board, int rMove, int cMove,
                 char color) {
    vector<vector<int>> dirs{{0, 1}, {1, 0},   {0, -1}, {-1, 0},
                             {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    char opp = 'W';
    if (color == 'W') {
      opp = 'B';
    }
    for (int d = 0; d < 8; ++d) {
      int nx = rMove + dirs[d][0];
      int ny = cMove + dirs[d][1];
      bool has_opp = false;
      bool same_end = false;
      for (; nx >= 0 && ny >= 0 && nx < 8 && ny < 8;
           nx += dirs[d][0], ny += dirs[d][1]) {
        if (board[nx][ny] == '.') {
          break;
        }
        if (board[nx][ny] == color) {
          same_end = true;
          break;
        } else if (!has_opp) {
          has_opp = true;
        }
      }
      if (has_opp && same_end) {
        return true;
      }
    }
    return false;
  }
};
