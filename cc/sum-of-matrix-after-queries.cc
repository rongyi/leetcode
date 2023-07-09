// https://leetcode.com/problems/sum-of-matrix-after-queries/
#include "xxx.hpp"

class Solution {
public:
  long long matrixSumQueries(int n, vector<vector<int>> &queries) {
    // remember the origin num
    vector<int> row(n, 0);
    vector<int> col(n, 0);
    int row_shadowed = 0;
    int col_shadowed = 0;

    long long sum = 0;

    // {updaterowcol?, index, val}
    for (int i = queries.size() - 1; i >= 0; i--) {
      // row update
      int type = queries[i][0];
      int index = queries[i][1];
      long long val = queries[i][2];
      if (type == 0 && !row[index]) {
        row[index] = 1;
        row_shadowed++;
        sum += val * (n - col_shadowed);
      }
      if (type == 1 && !col[index]) {
        col[index] = 1;
        col_shadowed++;
        sum += val * (n - row_shadowed);
      }
    }

    return sum;
  }
};
