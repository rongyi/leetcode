// http://leetcode.com/problems/surrounded-regions/description/
#include "one.h"

class Solution {
public:
  static const char kReplace = 'R';
  // 应该是从边上的O开始走，然后把这些标记为与X/O不一样的字符
  // 然后把特殊标记的字符再再标记回来
  void solve(vector<vector<char>> &board) {
    m_ = board.size();
    if (m_ == 0) {
      return;
    }
    n_ = board[0].size();
    if (n_ == 0) {
      return;
    }
    directions_ = vector<vector<int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    unordered_set<int> cache;
    for (int j = 0; j < n_; ++j) {
      // 第一行下手
      dfs(board, 0, j, cache);
      // 最后一行下手
      dfs(board, m_ - 1, j, cache);
    }
    for (int i = 1; i < m_ - 1; ++i) {
      // 第一列下手
      dfs(board, i, 0, cache);
      // 最后一列下手
      dfs(board, i, n_ - 1, cache);
    }
    // 还保持'O'的说明被包围了，干掉
    for (int i = 0; i < m_; i++) {
      for (int j = 0; j < n_; j++) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        } else if (board[i][j] == Solution::kReplace) {
          board[i][j] = 'O';
        }
      }
    }
  }

private:
  void dfs(vector<vector<char>> &board, int i, int j,
           unordered_set<int> &cache) {

    // 这里一开始的判断是board[i][j] ==
    // 'X'，然后超时了，应该同时还要排除替换掉的字符: 'R'
    // 所以这里干脆就直接判断是不是'O'，这里的细节注意一下
    if (i < 0 || i >= m_ || j < 0 || j >= n_ || board[i][j] != 'O' ||
        cache.find(i * n_ + j) != cache.end()) {
      return;
    }

    cache.insert(i * n_ + j);
    if (board[i][j] == 'O') {
      board[i][j] = Solution::kReplace;
    }

    for (int d = 0; d < 4; d++) {
      dfs(board, i + directions_[d][0], j + directions_[d][1], cache);
    }

    // resotre it back
    cache.erase(i * n_ + j);
  }

private:
  int m_;
  int n_;
  vector<vector<int>> directions_;
};
