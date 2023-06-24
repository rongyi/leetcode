// https://leetcode.com/problems/row-with-maximum-ones/
#include "xxx.hpp"

class Solution {
public:
  vector<int> rowAndMaximumOnes(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    int cnt = -1;
    int row = -1;
    for (int i = 0; i < m; i++) {
      int cur = 0;
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 1) {
          cur++;
        }
      }
      if (cur > cnt) {
        cnt = cur;
        row = i;
      }
    }
    return {row, cnt};
  }
};
