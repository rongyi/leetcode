// http://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/
#include "xxx.h"

class Solution {
public:
  // For each row, calculate the prefix sum.
  // For each pair of columns,
  // calculate the accumulated sum of rows.
  // Now this problem is same to, "Find the Subarray with Target Sum".
  int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
    const int m = matrix.size();
    const int n = matrix[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        matrix[i][j] += matrix[i][j - 1];
      }
    }

    int ret = 0;
    // i， j是两根纵轴，看好了
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        unordered_map<int, int> count;
        count[0] = 1;
        int cur_sum = 0;
        for (int k = 0; k < m; ++k) {
          // 如果左边的轴不是第一列，那么对应的检出prefix sum
          cur_sum += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
          ret += count[cur_sum - target];
          ++count[cur_sum];
        }
      }
    }

    return ret;
  }
};
