// http://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/description/
#include "xxx.h"

class Solution {
public:
  int maxSumTwoNoOverlap(vector<int> &A, int L, int M) {
    return max(maxNoOverlap(A, L, M, A.size()),
               maxNoOverlap(A, M, L, A.size()));
  }
private:
  int maxNoOverlap(vector<int> &A, int L, int M, int len) {
    vector<int> left(len + 1, 0);
    vector<int> right(len + 1, 0);

    int sum_left = 0;
    int sum_right = 0;
    for (int i = 0, j = len - 1; i < len; ++i, --j) {
      sum_left += A[i];
      sum_right += A[j];
      left[i + 1] = max(left[i], sum_left);
      right[j] = max(right[j + 1], sum_right);

      if (i + 1 >= L) {
        sum_left -= A[i + 1 - L];
      }
      if (i + 1 >= M) {
        sum_right -= A[j + M - 1];
      }
    }
    int ret = 0;
    for (auto i = 0; i < len; ++i) {
      ret = max(ret, left[i] + right[i]);
    }
    return ret;
  }
};
