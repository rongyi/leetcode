// http://leetcode.com/problems/strange-printer-ii/description/
#include "xxx.hpp"

class Solution {
public:
  bool isPrintable(vector<vector<int>> &grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    unordered_set<int> colors;
    vector<std::array<int, 4>> boundaris(61, {m, n, 0, 0});

    // 统计所有颜色的边界，我们用左上和右下表示
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        auto c = grid[i][j];
        colors.insert(c);
        boundaris[c][0] = min(boundaris[c][0], i);
        boundaris[c][1] = min(boundaris[c][1], j);
        boundaris[c][2] = max(boundaris[c][2], i);
        boundaris[c][3] = max(boundaris[c][3], j);
      }
    }
    // 无所谓顺序，反正每一轮如果有那么都能清掉一些，否则就拜拜
    while (colors.size()) {
      unordered_set<int> next_color;
      for (auto c : colors) {
        if (!uniq_color(boundaris[c][0], boundaris[c][1], boundaris[c][2],
                        boundaris[c][3], c, grid)) {
          next_color.insert(c);
        }
      }

      if (colors.size() == next_color.size()) {
        return false;
      }

      colors.swap(next_color);
    }
    return true;
  }

private:
  // 如果颜色一致那么就清掉它，清掉颜色用0,颜色值是> 0的，所以我们用0清
  bool uniq_color(int tli, int tlj, int bri, int brj, int cur_color,
                  vector<vector<int>> &grid) {
    for (int i = tli; i <= bri; ++i) {
      for (int j = tlj; j <= brj; ++j) {
        if (grid[i][j] > 0 && grid[i][j] != cur_color) {
          return false;
        }
      }
    }

    for (int i = tli; i <= bri; ++i) {
      for (int j = tlj; j <= brj; ++j) {
        grid[i][j] = 0;
      }
    }

    return true;
  }
};
