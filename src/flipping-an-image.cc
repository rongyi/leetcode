// http://leetcode.com/problems/flipping-an-image/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
    const int m = A.size();
    const int n = A[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n / 2; j++) {
        swap(A[i][j], A[i][n - j - 1]);
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        A[i][j] = (A[i][j] == 1 ? 0 : 1);
      }
    }
    return A;
  }
};
