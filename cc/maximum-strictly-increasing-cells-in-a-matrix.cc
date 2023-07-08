// https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix/
#include "xxx.hpp"

class Solution {
public:
  int maxIncreasingCells(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> tmp(m, vector<int>(n, 0));
    // val -> [{i, j}]
    map<int, vector<array<int, 2>>> val_postions;
    set<int> uniq_vals;
    vector<int> row_paths(m, 0);
    vector<int> col_paths(n, 0);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int val = -matrix[i][j];
        val_postions[val].push_back({i, j});
        uniq_vals.insert(val);
      }
    }
    for (int val : uniq_vals) {
      for (auto &pos : val_postions[val]) {
        int r = pos[0];
        int c = pos[1];
        tmp[r][c] = max(row_paths[r], col_paths[c]) + 1;
      }

      for (auto &pos : val_postions[val]) {
        int r = pos[0];
        int c = pos[1];
        row_paths[r] = max(row_paths[r], tmp[r][c]);
        col_paths[c] = max(col_paths[c], tmp[r][c]);
      }
    }

    return max(*max_element(row_paths.begin(), row_paths.end()),
               *max_element(col_paths.begin(), col_paths.end()));
  }
};
