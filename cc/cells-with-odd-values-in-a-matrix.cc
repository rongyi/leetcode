// http://leetcode.com/problems/cells-with-odd-values-in-a-matrix/description/
#include "xxx.hpp"

class Solution {
public:
  int oddCells(int m, int n, vector<vector<int>> &indices) {
    vector<int> row(m, 0);
    vector<int> col(n, 0);
    for (auto &p : indices) {
      ++row[p[0]];
      ++col[p[1]];
    }
    int ret = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        // 这个节点要加这么多次
        if ((row[i] + col[j]) & 1) {
          ++ret;
        }
      }
    }
    return ret;
  }
};
