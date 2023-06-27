// https://leetcode.com/problems/first-completely-painted-row-or-column/
#include "xxx.hpp"

class Solution {
public:
  int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat) {
    int sz = arr.size();
    int m = mat.size();
    int n = mat[0].size();

    vector<int> row_paint(m, 0);
    vector<int> col_paint(n, 0);
    // val -> (i, j)
    map<int, pair<int, int>> idx;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        idx[mat[i][j]] = {i, j};
      }
    }
    for (int i = 0; i < sz; i++) {
      auto p = idx[arr[i]];
      row_paint[p.first]++;
      col_paint[p.second]++;
      if (row_paint[p.first] == n || col_paint[p.second] == m) {
        return i;
      }
    }

    return sz - 1;
  }
};
