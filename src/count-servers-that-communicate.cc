// http://leetcode.com/problems/count-servers-that-communicate/description/
#include "xxx.h"

class Solution {
public:
  int countServers(vector<vector<int>> &grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<int> row(m, 0);
    vector<int> col(n, 0);
    int ret = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j]) {
          ++row[i];
          ++col[j];
          ++ret;
        }
      }
    }
    // 这样减也可以
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] && (row[i] == 1 && col[j] == 1)) {
          --ret;
        }
      }
    }
    return ret;
  }
};
