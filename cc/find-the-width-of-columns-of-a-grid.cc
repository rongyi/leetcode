// https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/
#include "xxx.hpp"

class Solution {
public:
  vector<int> findColumnWidth(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    auto length = [](int num) -> int {
      bool negtive = num < 0;
      long long n = num;
      if (negtive) {
        n = -n;
      }
      int sz = to_string(n).size();
      if (negtive) {
        sz += 1;
      }
      return sz;
    };
    vector<int> ret(n, 0);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        ret[j] = max(ret[j], length(grid[i][j]));
      }
    }
    return ret;
  }
};
