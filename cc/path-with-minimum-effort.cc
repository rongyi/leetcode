// http://leetcode.com/problems/path-with-minimum-effort/description/
#include "xxx.hpp"

class Solution {
public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    dirs_ = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    m_ = heights.size();
    n_ = heights[0].size();
    effort_ = numeric_limits<int>::max();

    int l = 0;
    int r = 1e6;
    while (l < r) {
      int mid = l + (r - l) / 2;

      can_reach_ = false;
      visited_ = vector<vector<int>>(m_, vector<int>(n_, 0));
      dfs(heights, 0, 0, mid);
      // 大了，到不了
      if (can_reach_) {
        r = mid;
      } else {
        // 小了，调大一点看看
        l = mid + 1;
      }
    }

    return l;
  }

private:
  // dfs pattern
  void dfs(vector<vector<int>> &height, int x, int y, int cur_max) {
    if (x == m_ - 1 && y == n_ - 1) {
      can_reach_ = true;
      return;
    }

    visited_[x][y] = 1;

    for (int i = 0; i < dirs_.size(); ++i) {
      auto nx = dirs_[i][0] + x;
      auto ny = dirs_[i][1] + y;
      // not valid or visited
      if (nx < 0 || nx >= m_ || ny < 0 || ny >= n_ || visited_[nx][ny]) {
        continue;
      }

      // 大的不让过
      auto diff = abs(height[nx][ny] - height[x][y]);
      if (diff > cur_max) {
        continue;
      }

      dfs(height, nx, ny, cur_max);
    }

    // 不弹
  }

private:
  vector<vector<int>> dirs_;
  int m_;
  int n_;
  vector<vector<int>> visited_;
  int effort_;
  bool can_reach_;
};

class SolutionTLE {
public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    dirs_ = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    m_ = heights.size();
    n_ = heights[0].size();
    effort_ = numeric_limits<int>::max();

    visited_ = vector<vector<int>>(m_, vector<int>(n_, 0));
    dfs(heights, 0, 0, 0);

    return effort_;
  }

private:
  // dfs pattern
  void dfs(vector<vector<int>> &height, int x, int y, int cur_effort) {
    // till the end
    if (x == m_ - 1 && y == n_ - 1) {
      effort_ = min(effort_, cur_effort);
      return;
    }
    visited_[x][y] = 1;

    for (int i = 0; i < dirs_.size(); ++i) {
      auto nx = dirs_[i][0] + x;
      auto ny = dirs_[i][1] + y;
      // not valid or visited or
      // 半路就已经发现这条路比已知的还要大, 没必要走下去了
      if (nx < 0 || nx >= m_ || ny < 0 || ny >= n_ || visited_[nx][ny] ||
          cur_effort >= effort_) {
        continue;
      }

      dfs(height, nx, ny, max(abs(height[x][y] - height[nx][ny]), cur_effort));
    }

    // dfs弹出
    visited_[x][y] = 0;
  }

private:
  vector<vector<int>> dirs_;
  int m_;
  int n_;
  vector<vector<int>> visited_;
  int effort_;
};
