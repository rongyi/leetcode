// http://leetcode.com/problems/super-washing-machines/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/super-washing-machines/discuss/99181/C%2B%2B-16ms-O(n)-solution-(with-trivial-proof)
  int findMinMoves(vector<int> &machines) {
    const int n = machines.size();
    // 前面留一个空的，从1开始放
    vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
      sum[i + 1] = sum[i] + machines[i];
    }
    if ((sum[n] % n) != 0) {
      return -1;
    }
    int avg = sum[n] / n;
    int ret = 0;
    for (int i = 0; i < n; i++) {
      // 到i的sum和是 sum[i + 1]
      // 所以左边是 sum[i]
      int l = i * avg - sum[i];
      int r = (n - i - 1) * avg - (sum[n] - sum[i] - machines[i]);
      if (l > 0 && r > 0) {
        ret = max(ret, abs(l) + abs(r));
      } else {
        ret = max(ret, max(abs(l), abs(r)));
      }
    }

    return ret;
  }
};
