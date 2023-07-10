// https://leetcode.com/problems/find-a-good-subset-of-the-matrix/
#include "xxx.hpp"

class Solution {
public:
  vector<int> goodSubsetofBinaryMatrix(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> vals;
    for (int i = 0; i < m; i++) {
      int val = 0;
      for (int j = 0; j < n; j++) {
        val |= (grid[i][j] << j);
      }
      vals.push_back(val);
    }
    for (int i = 0; i < m; i++) {
      if (vals[i] == 0) {
        return {i};
      }
      for (int j = i + 1; j < m; j++) {
        if ((vals[i] & vals[j]) == 0) {
          return {i, j};
        }
      }
    }
    return {};
  }
};
