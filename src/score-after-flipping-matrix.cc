// http://leetcode.com/problems/score-after-flipping-matrix/description/
#include "xxx.h"

class Solution {
public:
  // 这题非常赞
  int matrixScore(vector<vector<int>> &A) {
    const int m = A.size();
    const int n = A[0].size();
    // 首先让最高位的每一位都为1， 因为最高位比余下所有位加起来都大
    int ret = (1 << (n - 1)) * m;
    for (int j = 1; j < n; j++) {
      int cur = 0;
      for (int i = 0; i < m; i++) {
        cur += (A[i][j] == A[i][0]);
      }
      // 尽可能在每一列上都取得更多的1
      // 1多了就是这个，1少了，这一列就翻转，能得到的1个数就是m - cur
      ret += max(cur, m - cur) * (1 << (n - j - 1));
    }

    return ret;
  }
};
