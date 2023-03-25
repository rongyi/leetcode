// http://leetcode.com/problems/surrounded-regions/description/
#include "xxx.hpp"

class Solution {
public:
  // find 'O' from edge and replace
  void solve(vector<vector<char>> &board) {
    m_ = board.size();
    n_ = board[0].size();
    directions_ = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (int j = 0; j < n_; j++) {
      dfs(board, 0, j);
      dfs(board, m_ - 1, j);
    }
    for (int i = 0; i < m_; i++) {
      dfs(board, i, 0);
      dfs(board, i, n_ - 1);
    }
    for (int i = 0; i < m_; i++) {
      for (int j = 0; j < n_; j++) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        } else if (board[i][j] == 'R') {
          board[i][j] = 'O';
        }
      }
    }
  }

private:
  void dfs(vector<vector<char>> &board, int i, int j) {
    if (i < 0 || i >= m_ || j < 0 || j >= n_ || board[i][j] != 'O') {
      return;
    }
    board[i][j] = 'R';
    for (int d = 0; d < 4; d++) {
      dfs(board, i + directions_[d][0], j + directions_[d][1]);
    }
  }

private:
  int m_;
  int n_;
  vector<vector<int>> directions_;
};
