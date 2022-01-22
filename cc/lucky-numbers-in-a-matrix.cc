// http://leetcode.com/problems/lucky-numbers-in-a-matrix/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> luckyNumbers(vector<vector<int>> &matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<int> min_row(m, 0);
    vector<int> max_col(n, 0);

    for (int i = 0; i < m; ++i) {
      min_row[i] = *min_element(matrix[i].begin(), matrix[i].end());
    }
    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < m; ++i) {
        max_col[j] = max(max_col[j], matrix[i][j]);
      }
    }
    vector<int> ret;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (min_row[i] == max_col[j]) {
          ret.push_back(max_col[j]);
        }
      }
    }

    return ret;
  }
};
