// http://leetcode.com/problems/rotting-oranges/description/
#include "xxx.hpp"

class Solution {
public:
  // 0 empty
  // 1 good
  // 2 bad
  // start from bad, and bfs, calculate the min_round
  int orangesRotting(vector<vector<int>> &grid) {
    m_ = grid.size();
    n_ = grid[0].size();
    dirs_ = vector<vector<int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int num_good = 0;

    queue<pair<int, int>> q;
    for (int i = 0; i < m_; i++) {
      for (int j = 0; j < n_; j++) {
        if (grid[i][j] == 1) {
          ++num_good;
        }
        // bad orange
        if (grid[i][j] == 2) {
          q.push({i, j});
        }
      }
    }
    // 本身没有好水果直接返回0
    if (num_good == 0) {
      return 0;
    }

    int ret = -1;
    while (!q.empty()) {
      ret++;
      int num_level = q.size();
      for (int i = 0; i < num_level; i++) {
        auto cur = q.front();
        q.pop();
        // rotten this orange
        grid[cur.first][cur.second] = 2;
        for (int d = 0; d < 4; d++) {
          auto nx = cur.first + dirs_[d][0];
          auto ny = cur.second + dirs_[d][1];
          // 专找好苹果去污染,空忽略，烂苹果忽略
          if (nx < 0 || nx >= m_ || ny < 0 || ny >= n_ || grid[nx][ny] != 1) {
            continue;
          }
          // 并行的，免得从另外一个烂苹果过来又找到这个节点
          grid[nx][ny] = 2;
          --num_good;
          q.push({nx, ny});
        }
      }
    }

    // 有好苹果现在却出现烂不了的局面
    if (num_good) {
      return -1;
    }

    return ret;
  }

private:
  int m_;
  int n_;
  vector<vector<int>> dirs_;
};

int main() {
  Solution so;
  vector<vector<int>> input{{1}, {2}, {1}, {2}};
  auto ret = so.orangesRotting(input);
  cout << ret << endl;
  return 0;
}
