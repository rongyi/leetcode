// http://leetcode.com/problems/binary-subarrays-with-sum/description/
#include "xxx.hpp"

class Solution {
public:
  int numSubarraysWithSum(vector<int> &A, int S) {
    const int n = A.size();
    int left = 0;
    int cur_sum = 0;
    int ret = 0;

    for (int i = 0; i < n; i++) {
      cur_sum += A[i];
      while (left < i && cur_sum > S) {
        cur_sum -= A[left];
        left++;
      }
      if (cur_sum < S) {
        continue;
      }
      if (cur_sum == S) {
        ret++;
      }
      // 左边零挤掉也可以哎
      int t = left;
      while (t < i && A[t] == 0) {
        t++;
        ret++;
      }
    }
    return ret;
  }
};
