// http://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
#include "xxx.h"

class Solution {
public:
  // TODO: gdb follow
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    const int m = matrix.size();
    const int n = matrix[0].size();

    int maxsk = numeric_limits<int>::min();
    int cursum = 0;

    for (int l = 0; l < n; l++) {
      vector<int> sum(m);
      for (int c = l; c < n; c++) {
        cursum = 0;
        set<int> os;
        os.insert(0);
        for (int j = 0; j < m; j++) {
          sum[j] += matrix[j][c];
          cursum += sum[j];
          auto it = os.lower_bound(cursum - k);
          if (it != os.end())
            maxsk = max(maxsk, cursum - *it);
          os.insert(cursum);
        }
      }
    }
    return maxsk;
  }
};
