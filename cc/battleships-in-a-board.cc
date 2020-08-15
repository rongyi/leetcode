// http://leetcode.com/problems/battleships-in-a-board/description/
#include "xxx.h"

class Solution {
public:
  int countBattleships(vector<vector<char>> &board) {
    int ret = 0;
    const int m = board.size();
    if (m == 0) {
      return ret;
    }
    const int n = board[0].size();
    if (n == 0) {
      return ret;
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'X') {
          ++ret;
          reset(board, i, j);
        }
      }
    }

    return ret;
  }
private:
  // reset reset all column and row to dot
  void reset(vector<vector<char>> &board, int x, int y) {
    const int m = board.size();
    const int n = board[0].size();
    // reset should start from this point
    int i = x;
    // down
    while (i < m && board[i][y] == 'X') {
      board[i][y] = '.';
      i++;
    }
    // up
    i = x - 1;
    while (i >= 0 && board[i][y] == 'X') {
      board[i][y] = '.';
      i--;
    }

    // right
    // jump the x, y, it's already been set
    int j = y + 1;
    while (j < n && board[x][j] == 'X') {
      board[x][j] = '.';
      j++;
    }
    // left
    j = y - 1;
    while (j >= 0 && board[x][j] == 'X') {
      board[x][j] = '.';
      j--;
    }
  }
};

int main() {
  Solution so;
  vector<vector<char>> input{{'X', 'X', 'X'}};
  auto ret = so.countBattleships(input);
  cout << ret << endl;
}
