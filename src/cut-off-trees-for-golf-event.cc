// http://leetcode.com/problems/cut-off-trees-for-golf-event/description/
#include "xxx.h"

class Solution {
public:
  int cutOffTree(vector<vector<int>> &forest) {
    if (forest.empty() || forest[0].empty()) {
      return 0;
    }
    // preapare
    dirs_ = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    m_ = forest.size();
    n_ = forest[0].size();

    vector<vector<int>> trees;
    for (int i = 0; i < m_; i++) {
      for (int j = 0; j < n_; j++) {
        if (forest[i][j] > 1) {
          trees.push_back({forest[i][j], i, j});
        }
      }
    }
    sort(trees.begin(), trees.end());
    int ret = 0;

    for (int i = 0, cur_row = 0, cur_col = 0; i < trees.size(); i++) {
      auto step = nextStep(forest, cur_row, cur_col, trees[i][1], trees[i][2]);
      if (step == -1) {
        return -1;
      }
      ret += step;
      cur_row = trees[i][1];
      cur_col = trees[i][2];
    }

    return ret;
  }

private:
  int nextStep(vector<vector<int>> &forest, int sx, int sy, int ex, int ey) {
    if (sx == ex && sy == ey) {
      return 0;
    }
    queue<pair<int, int>> q;
    q.push({sx, sy});

    vector<vector<bool>> visited(m_, vector<bool>(n_, false));
    visited[sx][sy] = true;

    int step = 0;
    while (!q.empty()) {
      step++;
      int sz = q.size();
      for (int i = 0; i < sz; i++) {
        auto x = q.front().first;
        auto y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
          int nx = x + dirs_[i][0];
          int ny = y + dirs_[i][1];
          if (nx < 0 || nx >= m_ || ny < 0 || ny >= n_ || visited[nx][ny] ||
              forest[nx][ny] == 0) {
            continue;
          }
          if (nx == ex && ny == ey) {
            return step;
          }
          visited[nx][ny] = true;
          q.push({nx, ny});
        }
      }
    }
    // not found
    return -1;
  }

private:
  vector<vector<int>> dirs_;
  int m_;
  int n_;
};
