// http://leetcode.com/problems/sort-the-matrix-diagonally/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
    unordered_map<int, vector<int>> diags_;
    const int m = mat.size();
    const int n = mat[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        diags_[i - j].push_back(mat[i][j]);
      }
    }
    for (auto &kv : diags_) {
      sort(kv.second.begin(), kv.second.end());
      int idx = 0;
      for (int i = 0; i < m; i++) {
        // i - j = c ==> j =  i - c
        int j = i - kv.first;
        if (j < 0 || j >= n) {
          continue;
        }
        mat[i][j] = kv.second[idx++];
      }
    }
    return mat;
  }
};
