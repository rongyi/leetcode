// http://leetcode.com/problems/smallest-range-ii/description/
#include "xxx.hpp"

class Solution {
public:
  int smallestRangeII(vector<int> &A, int K) {
    // 先排序，然后设想有一个点，这个点左边全是加，右边全是减K
    // O(n)的推导出来
    sort(A.begin(), A.end());
    int left = A[0] + K;
    int right = A[A.size() - 1] - K;
    int ret = A[A.size() - 1] - A[0];
    for (int i = 0; i < A.size() - 1; i++) {
      int cur_max = max(A[i] + K, right);
      int cur_min = min(left, A[i + 1] - K);
      ret = min(ret, cur_max - cur_min);
    }

    return ret;
  }
};
