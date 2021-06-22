// http://leetcode.com/problems/cat-and-mouse-ii/description/
#include "xxx.h"

class Solution {
public:
  bool canMouseWin(vector<string> &grid, int cat_jump, int mouse_jump) {
    dirs_ = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    m_ = grid.size();
    n_ = grid[0].size();

    int cat_pos = 0;
    int mouse_pos = 0;
    int food_pos = 0;
    int turns = m_ * n_;

    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; ++j) {
        if (grid[i][j] == 'M') {
          mouse_pos = i * 8 + j;
        }
        if (grid[i][j] == 'C') {
          cat_pos = i * 8 + j;
        }
        if (grid[i][j] == 'F') {
          food_pos = i * 8 + j;
        }
      }
    }

    return dfs(grid, turns, cat_pos, mouse_pos, food_pos, cat_jump, mouse_jump);
  }

private:
  bool dfs(vector<string> &grid, int turn, int cat_pos, int mouse_pos,
           int food_pos, int cat_jump, int mouse_jump) {
    if (turn >= 0 &&
        (mouse_pos == food_pos || dp[turn][mouse_pos][cat_pos] == 1)) {
      return true;
    }
    if (turn < 0 || cat_pos == mouse_pos || cat_pos == food_pos ||
        dp[turn][mouse_pos][cat_pos] == -1) {
      return false;
    }
    auto cat_next_lst = get_jump(grid, cat_pos, food_pos, cat_jump);
    for (auto nm : get_jump(grid, mouse_pos, food_pos, mouse_jump)) {
      bool mwin = true;
      for (auto c = 0; mwin && c < cat_next_lst.size(); ++c) {
        mwin &= dfs(grid, turn - 1, cat_next_lst[c], nm, food_pos, cat_jump,
                    mouse_jump);
      }

      if (mwin) {
        return dp[turn][mouse_pos][cat_pos] = 1;
      }
    }

    dp[turn][mouse_pos][cat_pos] = -1;
    return false;
  }

  vector<int> get_jump(vector<string> &grid, int cur_pos, int food_pos,
                       int max_step) {
    vector<int> ret{cur_pos};
    for (int d = 0; d < 4; ++d) {
      for (int jump = 1; jump <= max_step; ++jump) {
        auto x = cur_pos / 8 + dirs_[d][0] * jump;
        auto y = cur_pos % 8 + dirs_[d][1] * jump;
        // not valid?
        if (x < 0 || y < 0 || x >= m_ || y >= n_ || grid[x][y] == '#') {
          break;
        }
        ret.push_back(x * 8 + y);
      }
    }
    // sort by distance to food
    sort(ret.begin(), ret.end(), [food_pos](int a, int b) {
      auto da = abs(food_pos / 8 - a / 8) + abs(food_pos % 8 - a % 8);
      auto db = abs(food_pos / 8 - b / 8) + abs(food_pos % 8 - b % 8);
      return da < db;
    });

    return ret;
  }

private:
  vector<vector<int>> dirs_;
  int m_;
  int n_;

  // FIXME: change 64 ==> 36
  // https://leetcode.com/problems/cat-and-mouse-ii/discuss/1023634/C%2B%2B-80-ms-(weak-test-cases)
  // We only need to consider the rows * ((cols + 1) / 2) + cols / 2 - 1 moves.
  // This is the length of the longest maze the mouse need to travel in the
  // rows * cols grid.
  int dp[65][64][64];
};
