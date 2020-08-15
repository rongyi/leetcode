// http://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
#include "xxx.h"
using Pair = pair<int, int>;

class Solution {
public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.push({matrix[0][0], 0});

    int ret = 0;
    while (k--) {
      auto p = pq.top();
      pq.pop();

      ret = p.first;

      int cell = p.second;
      int r = cell / n;
      int c = cell % n;

      int nextr = r + 1;
      int nextc = c + 1;
      if (c == 0 && nextr < m) {
        // 这里再把 (nextr, c) 坐标换算成值
        pq.push({matrix[nextr][c], nextr * n + c});
      }
      if (nextc < n) {
        // 同样把(r, nextc)坐标换算成值
        pq.push({matrix[r][nextc], r * n + nextc});
      }
    }

    return ret;
  }
};
