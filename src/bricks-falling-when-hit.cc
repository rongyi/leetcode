// https://leetcode.com/problems/bricks-falling-when-hit/description/
#include "one.h"

class Solution {
public:
  Solution() {
    //  from top to right to down to left
    dir_ = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  }
  vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
    // initialize variable
    row_ = grid.size();
    col_ = grid[0].size();
    visited_ = vector<vector<int>>(row_, vector<int>(col_, 0));

    vector<int> ret;
    for (auto h : hits) {
      int r = h[0], c = h[1];
      int removal = 0;
      if (grid[r][c] == 1) {
        grid[r][c] = 0; // clear this brick
        for (int d = 0; d < 4; d++) {
          int x = r + dir_[d][0], y = c + dir_[d][1];
          if (!valid(x, y) || grid[x][y] == 0) {
            continue;
          }
          // 四个方向上的砖块也许去掉这个砖块之后就是分散的几个群，所以每次各个方向作为一次独立事件处理。
          // 如果是联通的话任意一个方向dfs之后都会被清掉，所以后续其他方向的访问不会再遇到了，因为已经被
          // 当成掉落清理掉了
          ++id_; // mark each connecting parts with a unique id_ in this run
          if (falling(grid, x, y)) {
            removal += count(grid, x, y);
          }
        }
      }
      ret.push_back(removal);
    }
    return ret;
  }

private:
  bool falling(vector<vector<int>> &grid, int r, int c) {
    if (!valid(r, c) || grid[r][c] == 0) {
      return true;
    }
    // 等于什么意思呢？就是说本来是想问这块砖头会不会掉下来然后开始去dfs这块砖头四周的砖头
    // 结果在遍历其他砖头的时候其他砖头的四周又回到这个砖头了，所以用这个缓存来标记
    // 询问falling的动作本来就是“我”这块砖头发起的，结果倒好现在转了一圈又绕到
    // “我”头上了。所以回答会掉意思也是不要问我，问我周围的砖块。我说不掉不起作用
    if (visited_[r][c] == id_) {
      return true;
    }
    if (r == 0) {
      return false; // connecting 1st row
    }
    visited_[r][c] = id_;
    for (int d = 0; d < 4; ++d) {
      if (!falling(grid, r + dir_[d][0], c + dir_[d][1])) {
        return false;
      }
    }
    return true;
  }
  // 算count时候已经明确知道这块砖头会掉落，所以就只是dfs把整个块给算下来
  int count(vector<vector<int>> &grid, int r, int c) {
    if (!valid(r, c) || grid[r][c] == 0) {
      return 0;
    }
    int ret = 1;
    grid[r][c] = 0;
    for (int d = 0; d < 4; ++d) {
      ret += count(grid, r + dir_[d][0], c + dir_[d][1]);
    }
    return ret;
  }
  bool valid(int r, int c) {
    return 0 <= r && r < row_ && 0 <= c && c < col_;
  }
private:
  vector<vector<int>> dir_;
  vector<vector<int>> visited_;
  int row_;
  int col_;
  int id_;
};

int main() {
  Solution so;
  vector<vector<int>> grid{{1, 0, 0, 0}, {1, 1, 1, 0}};
  vector<vector<int>> hits{{1, 0}};

  auto ret = so.hitBricks(grid, hits);
  for (auto i : ret) {
    cout << i << endl;
  }
}
