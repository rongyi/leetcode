// http://leetcode.com/problems/word-search/description/
#include "xxx.hpp"

class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    directions_ = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    m_ = board.size();
    n_ = board[0].size();
    vector<vector<bool>> visited(m_, vector<bool>(n_, 0));

    for (int i = 0; i < m_; i++) {
      for (int j = 0; j < n_; j++) {
        if (search(board, word, 0, i, j, visited)) {
          return true;
        }
      }
    }
    return false;
  }

private:
  bool search(vector<vector<char>> &board, string &word, int widx, int x, int y,
              vector<vector<bool>> &visited) {
    visited[x][y] = true;
    if (board[x][y] == word.at(widx)) {
      widx++;
      if (widx == word.size()) {
        return true;
      }
      for (int d = 0; d < 4; d++) {
        int nx = x + directions_[d][0];
        int ny = y + directions_[d][1];
        if (nx < 0 || nx >= m_ || ny < 0 || ny >= n_ || visited[nx][ny]) {
          continue;
        }
        auto peek = search(board, word, widx, nx, ny, visited);
        if (peek) {
          return true;
        }
      }
    }

    visited[x][y] = false;

    return false;
  }

private:
  vector<vector<int>> directions_;
  int m_;
  int n_;
};
