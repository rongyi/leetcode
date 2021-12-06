// https://leetcode.com/problems/maximum-matrix-sum/
#include "xxx.h"

class Solution {
public:
  // we can always pair two negative num together and make them postive
  // the last one? we can do nothing about this one
  long long maxMatrixSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    long long sum = 0;
    int min_num = numeric_limits<int>::max();
    int neg_count = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] < 0) {
          neg_count++;
        }
        sum += abs(matrix[i][j]);
        min_num = min(abs(matrix[i][j]), min_num);
      }
    }
    if (neg_count & 1) {
      sum -= min_num * 2;
    }

    return sum;
  }
};
