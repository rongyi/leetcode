// http://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/
#include "one.h"

class Solution {
public:
  int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
    int ret = 0;
    const int n = A.size();
    for (int i = 0; i < n; i++) {
      if (A[i] > R) {
        continue;
      }
      int cur_max = numeric_limits<int>::min();
      for (int j = i; j < n; j++) {
        cur_max = max(cur_max, A[j]);
        if (cur_max > R) {
          break;
        }
        if (cur_max >= L) {
          ++ret;
        }
      }
    }

    return ret;
  }
};
