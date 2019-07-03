// http://leetcode.com/problems/partition-array-into-disjoint-intervals/description/
#include "xxx.h"

class Solution {
public:
  int partitionDisjoint(vector<int> &A) {
    const int n = A.size();
    // from right to left
    vector<int> cur_min(n, numeric_limits<int>::max());
    // from left to right
    vector<int> cur_max(n, -1);

    int tmp = -1;
    for (int i = 0; i < n; i++) {
      tmp = max(tmp, A[i]);
      cur_max[i] = tmp;
    }
    tmp = numeric_limits<int>::max();
    for (int i = n - 1; i >= 0; i--) {
      tmp = min(tmp, A[i]);
      cur_min[i] = tmp;
    }

    int i = 1;
    for (; i < n; i++) {
      // 符合要求
      if (cur_max[i - 1] <= cur_min[i]) {
        break;
      }
    }

    return i;
  }
};
