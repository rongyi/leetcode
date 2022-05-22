// https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/
#include "xxx.hpp"

class Solution {
public:
  bool hasValidPath(vector<vector<char>> &grid) {
    m_ = grid.size();
    n_ = grid[0].size();

    return dfs(grid, 0, 0, 0);
  }

private:
  bool dfs(vector<vector<char>> &grid, int x, int y, int balance) {
    // ( +
    // ) -
    if (grid[x][y] == '(') {
      balance += 1;
    } else {
      balance -= 1;
    }
    if (balance < 0 || balance > (m_ + n_) / 2 || visited[x][y][balance]) {
      return false;
    }
    visited[x][y][balance] = true;
    if (x == m_ - 1 && y == n_ - 1 && balance == 0) {
      return true;
    }
    if (x < m_ - 1 && dfs(grid, x + 1, y, balance)) {
      return true;
    }
    if (y < n_ - 1 && dfs(grid, x, y + 1, balance)) {
      return true;
    }

    return false;
  }

private:
  int m_;
  int n_;
  int visited[100][100][101] = {};
};
