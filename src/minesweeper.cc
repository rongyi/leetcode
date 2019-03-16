// http://leetcode.com/problems/minesweeper/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                   vector<int> &click) {
    m_ = board.size();
    n_ = board[0].size();
    // eight directions
    dirs_ = {{0, 1},   {1, 0}, {0, -1}, {-1, 0},
             {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

    int x = click[0];
    int y = click[1];
    // boom!
    if (board[x][y] == 'M') {
      board[x][y] = 'X';
      return board;
    }
    // count neighbor mine
    vector<vector<int>> mines(m_, vector<int>(n_, 0));
    countMines(board, mines);
    // then the click position must be 'E' empty
    // board[x][y] = 'B';
    vector<vector<bool>> visited(m_, vector<bool>(n_, false));
    // dfs
    dfs(board, mines, x, y, visited);

    return board;
  }

private:
  void dfs(vector<vector<char>> &board, vector<vector<int>> &count, int i,
           int j, vector<vector<bool>> &visited) {
    if (!valid(i, j) || visited[i][j]) {
      return;
    }
    visited[i][j] = true;
    if (count[i][j] == 0) {
      board[i][j] = 'B';
      for (auto dir : dirs_) {
        int ni = i + dir[0];
        int nj = j + dir[1];
        dfs(board, count, ni, nj, visited);
      }
    } else {
      board[i][j] = '0' + count[i][j];
      // and we stop here
    }
  }

  void countMines(vector<vector<char>> &board, vector<vector<int>> &count) {
    for (int i = 0; i < m_; i++) {
      for (int j = 0; j < n_; j++) {
        if (board[i][j] == 'M') {
          for (auto dir : dirs_) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            if (valid(ni, nj)) {
              count[ni][nj]++;
            }
          }
        }
      }
    }
  }

  bool valid(int i, int j) {
    if (i < 0 || i >= m_ || j < 0 || j >= n_) {
      return false;
    }
    return true;
  }

private:
  int m_;
  int n_;
  vector<vector<int>> dirs_;
};
