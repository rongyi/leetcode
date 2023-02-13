// http://leetcode.com/problems/n-queens/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    ret_.clear();
    cols_ = vector<int>(n, 0);
    rows_ = vector<int>(n, 0);

    dfs(0, n);

    return ret_;
  }

private:
  void dfs(int row, int n) {
    if (row == n) {
      vector<string> newlayout;
      for (int i = 0; i < n; i++) {
        string cur_row(n, '.');
        cur_row[rows_[i]] = 'Q';
        newlayout.push_back(cur_row);
      }
      ret_.push_back(newlayout);
      return;
    }
    for (int j = 0; j < n; j++) {
      bool ok =
          cols_[j] == 0 && !diag1_.count(row + j) && !diag2_.count(row - j);
      if (!ok) {
        continue;
      }
      cols_[j] = 1;
      rows_[row] = j;
      diag1_.insert(row + j);
      diag2_.insert(row - j);

      dfs(row + 1, n);

      cols_[j] = 0;
      diag1_.erase(row + j);
      diag2_.erase(row - j);
    }
  }

private:
  vector<vector<string>> ret_;

  // cols[j] == 1 have queen
  vector<int> cols_;
  // rows_[i] = j --> matrix[i][j] = 'Q'
  vector<int> rows_;

  // i + j
  set<int> diag1_;
  // i - j
  set<int> diag2_;
};
