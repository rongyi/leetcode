// https://leetcode.com/problems/increment-submatrices-by-one/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries) {
    sort(queries.begin(), queries.end());
    vector<vector<int>> ret(n, vector<int>(n, 0));
    for (auto &q : queries) {
      for (int i = q[0]; i <= q[2]; ++i) {
        ret[i][q[1]] += 1;
        if (q[3] + 1 < n) {
          ret[i][q[3] + 1] -= 1;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j < n; ++j) {
        ret[i][j] += ret[i][j - 1];
      }
    }

    return ret;
  }
};
