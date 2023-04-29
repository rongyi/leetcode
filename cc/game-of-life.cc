// http://leetcode.com/problems/game-of-life/description/
#include "xxx.hpp"

class Solution {
public:
  void gameOfLife(vector<vector<int>> &board) {
    const int m = board.size();
    if (m == 0) {
      return;
    }
    const int n = board[0].size();
    directions_ = vector<vector<int>>{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                      {0, 1},   {1, -1}, {1, 0},  {1, 1}};
    // 懒得编码了，其实还可以在原来的位置设置值，然后不同的值标记为从 0 -> 1
    // 或者从 1 -> 0这个过程
    vector<vector<int>> shadow = board;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // Any dead cell with exactly three live neighbors becomes a live cell,
        // as if by reproduction.
        if (board[i][j] == 0) {
          auto cnt = myLiveNeighbor(board, i, j, m, n);
          if (cnt == 3) {
            shadow[i][j] = 1;
          }
        } else {
          auto cnt = myLiveNeighbor(board, i, j, m, n);
          // Any live cell with fewer than two live neighbors dies, as if caused
          // by under-population. Any live cell with more than three live
          // neighbors dies, as if by over-population..
          if (cnt < 2 || cnt > 3) {
            shadow[i][j] = 0;
          }
        }
      }
    }
    board = shadow;
  }

private:
  int myLiveNeighbor(vector<vector<int>> &board, int i, int j, const int m,
                     const int n) {
    int ret = 0;
    for (int d = 0; d < directions_.size(); d++) {
      auto curi = i + directions_[d][0];
      auto curj = j + directions_[d][1];
      // out of matrix
      if (curi < 0 || curi >= m || curj < 0 || curj >= n) {
        continue;
      }
      if (board[curi][curj] == 1) {
        ret++;
      }
    }
    return ret;
  }

private:
  vector<vector<int>> directions_;
};
