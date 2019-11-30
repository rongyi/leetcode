// http://leetcode.com/problems/shift-2d-grid/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
    const int cnt = grid.size() * grid[0].size();
    k %= cnt;
    // fast path
    if (k == 0) {
      return grid;
    }
    vector<int> flat;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        flat.push_back(grid[i][j]);
      }
    }
    // 拼起来，然后从shift处开始
    vector<int> concat = flat;
    concat.insert(concat.end(), flat.begin(), flat.end());
    for (int i = flat.size() - k, len = 0; len < cnt; ++len) {
      grid[len / grid[0].size()][len % grid[0].size()] = concat[i++];
    }
    return grid;
  }
};
