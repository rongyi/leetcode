// http://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum) {
    const int m = rowSum.size();
    const int n = colSum.size();
    vector<vector<int>> ret(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ret[i][j] = min(rowSum[i], colSum[j]);
        rowSum[i] -= ret[i][j];
        colSum[j] -= ret[i][j];
      }
    }

    return ret;
  }
};
