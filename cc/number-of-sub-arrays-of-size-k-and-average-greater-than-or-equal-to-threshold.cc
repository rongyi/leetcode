// http://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/
#include "xxx.h"

class Solution {
public:
  int numOfSubarrays(vector<int> &arr, int k, int threshold) {
    const int n = arr.size();
    vector<int> sum(n + 1, 0);
    for (int i = 1; i < sum.size(); i++) {
      sum[i] = sum[i - 1] + arr[i - 1];
    }
    int ret = 0;
    for (int i = 0; i + k - 1 < n; i++) {
      auto cursum = sum[i + k] - sum[i];
      if (cursum / k >= threshold) {
        ++ret;
      }
    }

    return ret;
  }
};
