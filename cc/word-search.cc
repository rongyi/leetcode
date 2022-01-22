// http://leetcode.com/problems/word-search/description/
#include "xxx.hpp"

class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    // init
    directions_ = vector<vector<int>>{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    m_ = board.size();
    if (m_ == 0) {
      return false;
    }
    n_ = board[0].size();
    if (word.empty()) {
      return true;
    }

    vector<vector<bool>> visited(m_, vector<bool>(n_, false));

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
  bool search(vector<vector<char>> &board, string &word, int cur_index, int i,
              int j, vector<vector<bool>> &cache) {
    if (i < 0 || i >= m_ || j < 0 || j >= n_ || cache[i][j] == true) {
      return false;
    }
    // mark
    cache[i][j] = true;

    bool ret = false;

    if (board[i][j] == word.at(cur_index)) {
      if (cur_index == word.size() - 1) {
        return true;
      }

      for (int d = 0; d < 4; d++) {
        auto next = search(board, word, cur_index + 1, directions_[d][0] + i,
                           directions_[d][1] + j, cache);
        if (next) {
          return true;
        }
      }
    }

    // restore
    cache[i][j] = false;
    return ret;
  }

private:
  vector<vector<int>> directions_;
  int m_;
  int n_;
};
