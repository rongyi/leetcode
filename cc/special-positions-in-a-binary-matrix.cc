// http://leetcode.com/problems/special-positions-in-a-binary-matrix/description/
#include "xxx.hpp"

class Solution {
public:
  int numSpecial(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> row(m, 0);
    vector<int> col(n, 0);
    vector<pair<int, int>> sparse;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 1) {
          row[i]++;
          col[j]++;
          sparse.push_back({i, j});
        }
      }
    }
    int ret = 0;
    for (auto &p : sparse) {
      if (row[p.first] == 1 && col[p.second] == 1) {
        ++ret;
      }
    }

    return ret;
  }
};
