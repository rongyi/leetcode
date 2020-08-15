// https://leetcode.com/problems/transpose-matrix/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> transpose(vector<vector<int>> &A) {
    const int m = A.size();
    const int n = A[0].size();

    vector<vector<int>> ret(n, vector<int>(m, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ret[j][i] = A[i][j];
      }
    }

    return ret;
  }
};
